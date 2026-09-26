# ============================================================
#  四足狗 MuJoCo 静止趴地仿真
#  - 双线程架构：物理步进线程 + 渲染线程
#  - 锁保护：mj_step 与 viewer.sync 互斥，防止数据竞争
#  - 关节力矩恒为 0，符合任务要求
#  - 结构参考 unitree_mujoco 官方示例
# ============================================================

import time
import threading
import numpy as np

import mujoco
import mujoco.viewer


# ============================================================
#  1. 加载模型与数据
# ============================================================
MODEL_PATH = "black_description_optimization.xml"

model = mujoco.MjModel.from_xml_path(MODEL_PATH)
data  = mujoco.MjData(model)

# 全局锁：保护 mj_step 与 viewer.sync 不会同时访问 data
# 物理线程持锁时，渲染线程等待；反之亦然。
locker = threading.Lock()


# ============================================================
#  2. 初始趴地姿态设置
#     qpos 索引说明：
#       [0:3]   基座位置 (x, y, z)
#       [3:7]   基座姿态四元数 (w, x, y, z)
#       [7:19]  12 个关节角，顺序为：
#               FL_hip, FL_thigh, FL_calf,
#               FR_hip, FR_thigh, FR_calf,
#               RR_hip, RR_thigh, RR_calf,
#               RL_hip, RL_thigh, RL_calf
# ============================================================
def init_prone_pose():
    """设置初始趴地姿态：基座略高于地，四条腿弯曲折叠。"""

    # --- 基座位置 ---
    # z 值需要根据趴地时足底到基座的距离微调。
    # 若狗脚穿地 -> 增大 z；若狗脚悬空下坠 -> 减小 z。
    data.qpos[0] = 0.0
    data.qpos[1] = 0.0
    data.qpos[2] = 0.45

    # --- 基座姿态：单位四元数，无旋转 ---
    data.qpos[3:7] = [1.0, 0.0, 0.0, 0.0]

    # --- 12 个关节角：四条腿对称折叠，趴地 ---
    # 前腿：膝盖向后弯，calf 取负
    # 后腿：膝盖向前弯，calf 取正
    # （与 XML 中各 calf 关节的限位一致）
    FL_hip, FL_thigh, FL_calf = 0.0,  0.7, -1.6
    FR_hip, FR_thigh, FR_calf = 0.0, -0.7,  1.6
    RR_hip, RR_thigh, RR_calf = 0.0, -0.7,  1.6
    RL_hip, RL_thigh, RL_calf = 0.0,  0.7, -1.6

    data.qpos[7:19] = [
        FL_hip, FL_thigh, FL_calf,
        FR_hip, FR_thigh, FR_calf,
        RR_hip, RR_thigh, RR_calf,
        RL_hip, RL_thigh, RL_calf,
    ]

    # 让模型状态与 qpos 一致（计算前向运动学、接触等）
    mujoco.mj_forward(model, data)


# 设置初始姿态
init_prone_pose()

# 任务要求：所有关节力矩输出为 0
data.ctrl[:] = 0.0


# ============================================================
#  3. 线程函数
# ============================================================
def simulation_thread():
    """
    物理步进线程：
      - 以 1/timestep 的频率执行 mj_step
      - 持锁期间渲染线程不能 sync，保证数据一致
    """
    while viewer.is_running():
        step_start = time.perf_counter()

        with locker:
            data.ctrl[:] = 0.0          # 始终保持力矩为 0
            mujoco.mj_step(model, data) # 物理步进

        # 固定仿真步长：若这一步算得快，就补足睡眠时间
        elapsed = time.perf_counter() - step_start
        sleep_time = model.opt.timestep - elapsed
        if sleep_time > 0:
            time.sleep(sleep_time)


def viewer_thread():
    """
    渲染线程：
      - 以约 50 Hz 调用 viewer.sync
      - 持锁期间物理线程不能 mj_step
    """
    while viewer.is_running():
        with locker:
            viewer.sync()
        time.sleep(0.02)   # 50 Hz


# ============================================================
#  4. 主入口：启动 viewer 与两个线程
# ============================================================
with mujoco.viewer.launch_passive(model, data) as viewer:
    time.sleep(0.2)  # 等 viewer 初始化完毕

    sim_thread = threading.Thread(target=simulation_thread, daemon=True)
    vis_thread = threading.Thread(target=viewer_thread,     daemon=True)

    sim_thread.start()
    vis_thread.start()

    print("仿真启动：关节力矩 = 0，狗应静止趴地。关闭窗口退出。")

    # 主线程等待两个工作线程结束（关闭窗口后 daemon 线程自动退出）
    sim_thread.join()
    vis_thread.join()

print("仿真结束。")