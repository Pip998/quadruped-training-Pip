import time
import threading
import numpy as np
import os
import rclpy # ros2库
from rclpy.node import Node
from dog_msgs.msg import ControllerCommand # 自定义消息类型 下同
from dog_msgs.msg import MotorState 
from sensor_msgs.msg import Imu # 给imu单开个sensor的msg
import mujoco
import mujoco.viewer

class SimulationNode(Node):
    def __init__(self): # 初始化工作
        super().__init__("node2_simulation")

        # 控制器～仿真
        self.command_subscriber = self.create_subscription(
            ControllerCommand,
            "controller_command",
            self.controller_command_callback,
            10
        )

        # 仿真～控制器
        self.motor_state_publisher = self.create_publisher(
            MotorState,
            "motor_state",
            10
        )

        self.imu_publisher = self.create_publisher(
            Imu,
            "imu",
            10
        )

        self.motor_state_timer = self.create_timer(
            0.01,
            self.publish_motor_state
        )
        self.imu_timer = self.create_timer(
            0.01,
            self.publish_imu
        )

        # 接收五行十二个电机的参数
        self.kp = np.zeros(12)
        self.kd = np.zeros(12)
        self.q_des = np.zeros(12)
        self.w_des = np.zeros(12)
        self.tau_ff = np.zeros(12)
        self.TARGET_SLEW_RATE = 0.01        # 顺带设置站立的渐变参数
        self.stand_target = np.zeros(12)    # 实际用于PD控制的逐步变化目标
        self.control_mode = "damping"       # 当前控制模式

        # 未收到参数，初始化布尔值
        self.command_received = False

        # 上锁，防止ROS回调线程和MuJoCo线程同时访问
        self.lock = threading.Lock()

        # 给mujoco xml文件的路径
        MODEL_PATH = os.path.join(os.path.dirname(__file__), "black_description_pinkoptimization.xml")

        self.model = mujoco.MjModel.from_xml_path(MODEL_PATH)
        self.data = mujoco.MjData(self.model)

        # 初始关节输出 = 0
        self.init_prone_pose()
        self.data.ctrl[:] = 0.0
        self.get_logger().info("仿真节点初始化")

    # 控制器～仿真
    def controller_command_callback(self, msg):
        with self.lock:
            # 装填5*12参数
            self.kp = np.array(msg.kp)
            self.kd =   [               # 初始就是阻尼慢慢趴下，kd一直设为3.0
                        3.0, 3.0, 3.0,  # FL
                        3.0, 3.0, 3.0,  # FR
                        3.0, 3.0, 3.0,  # RR
                        3.0, 3.0, 3.0   # RL
                        ]
            self.q_des = np.array(msg.q)
            self.w_des = np.array(msg.w)
            self.tau_ff = np.array(msg.tau)
        # 判断当前是站立模式还是阻尼模式
        if np.any(np.abs(self.kp) > 1e-9):
            new_mode = "stand"
        else:
            new_mode = "damping"

        # 如果刚刚从趴卧切换到站立
        if new_mode == "stand" and self.control_mode != "stand":

            # 从机器人当前姿态开始逐渐站立
            with self.lock:
                self.stand_target = self.data.qpos[7:19].copy()

        self.control_mode = new_mode

        self.command_received = True

        self.get_logger().info(
            "收到控制器指令"
        )

    # 机器人姿态初始化，照搬上上次任务文件
    def init_prone_pose(self):

        self.data.qpos[0] = 0.0
        self.data.qpos[1] = 0.0
        self.data.qpos[2] = 0.45

        self.data.qpos[3:7] = [
            1.0, 0.0, 0.0, 0.0
        ]

        self.data.qpos[7:19] = [
            0.0,  0.7, -1.6,    # FL
            0.0, -0.7,  1.6,    # FR
            0.0, -0.7,  1.6,    # RR
            0.0,  0.7, -1.6     # RL
        ]

        mujoco.mj_forward(
            self.model,
            self.data
        )

    # MuJoCo仿真线程
    def simulation_thread(self):
        while rclpy.ok(): # 一直运行仿真
            step_start = time.perf_counter()
            with self.lock:
                # 当前电机状态
                q = self.data.qpos[7:19].copy()
                dq = self.data.qvel[6:18].copy()
                if not self.command_received:   # 未受到指令依旧保持0
                    self.data.ctrl[:] = 0.0
                elif self.control_mode == "damping":
                    self.data.ctrl[:] = -3.0 * dq
                else:
                    # 目标逐渐向站立目标靠近
                    self.stand_target += (self.q_des - self.stand_target) * self.TARGET_SLEW_RATE

                    # 电机公式
                    control_torque = (self.kp * (self.stand_target - q) + self.kd * (self.w_des - dq) + self.tau_ff)
                    self.data.ctrl[:] = control_torque

                # Mujoco步进
                mujoco.mj_step(
                    self.model,
                    self.data
                )

            # 控制仿真速率尽可能接近现实
            elapsed = time.perf_counter() - step_start
            sleep_time = (
                self.model.opt.timestep - elapsed
            )
            if sleep_time > 0:
                time.sleep(sleep_time) # 快了就等一等～
            
    # 仿真～控制器
    def publish_motor_state(self):
        # 开始读数据
        with self.lock: 
            q = self.data.qpos[7:19].copy()
            dq = self.data.qvel[6:18].copy()
            # 关节加速度beta
            ddq = self.data.qacc[6:18].copy()
            # 当前力矩
            tau = self.data.actuator_force[:12].copy()

        msg = MotorState()
        msg.q = q.tolist()
        msg.dq = dq.tolist()
        msg.tau = tau.tolist()
        msg.ddq = ddq.tolist()
        # 电流读不到，置0
        msg.cur = [0.0] * 12
        # msg.ddq = [0.0] * 12

        self.motor_state_publisher.publish(msg)

    # 仿真～控制器（IMU）
    def publish_imu(self):
        msg = Imu()
        # 先填入机器人基座姿态
        with self.lock:

            quat = self.data.qpos[3:7].copy()
            gyro = self.data.qvel[3:6].copy()
            accel = self.data.qacc[0:3].copy()

        msg.orientation.w = float(quat[0])
        msg.orientation.x = float(quat[1])
        msg.orientation.y = float(quat[2])
        msg.orientation.z = float(quat[3])

        msg.angular_velocity.x = float(gyro[0])
        msg.angular_velocity.y = float(gyro[1])
        msg.angular_velocity.z = float(gyro[2])

        msg.linear_acceleration.x = float(accel[0])
        msg.linear_acceleration.y = float(accel[1])
        msg.linear_acceleration.z = float(accel[2])

        self.imu_publisher.publish(msg)

    # 开Mujoco窗口
    def viewer_thread(self):
        with mujoco.viewer.launch_passive(
            self.model,
            self.data
        ) as viewer:

            while rclpy.ok() and viewer.is_running():

                with self.lock: # 仿真一步就锁一下
                    viewer.sync()
                time.sleep(0.005)

def main(args=None):
    rclpy.init(args=args)
    node = SimulationNode()

    # 线程1：Mujoco仿真
    sim_thread = threading.Thread(
        target=node.simulation_thread,
        daemon=True
    )

    # 线程2：Mujoco可视化
    viewer_thread = threading.Thread(
        target=node.viewer_thread,
        daemon=True
    )
    sim_thread.start()
    viewer_thread.start()

    # ROS2主线程
    try:
        rclpy.spin(node) # 开始挂着
    except KeyboardInterrupt: # 强制退出control c
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()