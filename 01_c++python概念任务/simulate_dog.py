import time
import numpy as np
import mujoco
import mujoco.viewer

# ============ 加载 mujoco 模型 ============
model = mujoco.MjModel.from_xml_path("black_description.xml")
data = mujoco.MjData(model)

# ============ 设置趴地初始姿态 ============
# qpos 顺序：
#   [0:3]   基座位置 (x, y, z)
#   [3:7]   基座四元数 (w, x, y, z)
#   [7:19]  12 个关节角，顺序按 XML 中 joint 出现顺序：
#           FL_hip, FL_thigh, FL_calf,
#           FR_hip, FR_thigh, FR_calf,
#           RR_hip, RR_thigh, RR_calf,
#           RL_hip, RL_thigh, RL_calf

# 1) 基座初始位置：略高于地面，让足底刚好接触地面
data.qpos[0] = 0.0
data.qpos[1] = 0.0
data.qpos[2] = 0.45          # ★ 若py穿地就调大，若悬空就调小

# 2) 基座姿态：单位四元数，无旋转
data.qpos[3:7] = [1.0, 0.0, 0.0, 0.0]

# 3) 12 个关节角：让狗呈“趴地”姿态
#    参考 XML 限位：
#      hip:   [-0.5,  0.5]
#      FL/RL thigh: [-1.2, 1.6]   FR/RR thigh: [-1.6, 1.2]
#      FL/RL calf:  [-2.5, -0.85]  FR/RR calf:  [0.85, 2.5]
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

# 4) 先做一次前向计算，使模型状态与 qpos 一致
mujoco.mj_forward(model, data)

# ============ 任务要求：所有关节力矩输出置 0 ============
data.ctrl[:] = 0.0

# ============ 启动被动仿真窗口 ============
with mujoco.viewer.launch_passive(model, data) as viewer:
    print("仿真启动，关闭窗口退出")
    while viewer.is_running():
        
        step_start = time.time()

        # 每次步进前都保持力矩为 0
        data.ctrl[:] = 0.0

        # 仿真一步
        mujoco.mj_step(model, data)

        # 更新画面
        viewer.sync()

        # 打印状态，便于判断是否稳定趴地
        if int(data.time * 100) % 100 == 0:
            print("t=%.2f  base_z=%.4f  |qvel|=%.4f"
                  % (data.time, data.qpos[2], np.linalg.norm(data.qvel)))

        # 时间同步，固定仿真步长
        time_cost = time.time() - step_start
        if time_cost < model.opt.timestep:
            time.sleep(model.opt.timestep - time_cost)
