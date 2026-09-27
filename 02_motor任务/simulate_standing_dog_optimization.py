# ============================================================
#  四足狗 MuJoCo 站立/阻尼双模式仿真
#  - 双线程架构：物理步进线程 + 渲染线程
#  - 锁保护：mj_step 与 viewer.sync 互斥
#  - 支持两种键盘输入方式：
#      ① 鼠标点击仿真窗口后，按 空格 / S
#      ② 在终端中，输入“空格回车”或“s回车”
# ============================================================

import time
import threading
import numpy as np

import mujoco
import mujoco.viewer


# ============================================================
#  0. 模式与参数
# ============================================================
MODE_DAMPING = 0    # 阻尼模式
MODE_STAND   = 1    # 站立模式

# 站立模式的“渐变目标”，初始为 None
stand_target = None
# 渐变速率：0.005 ~ 0.02 之间比较合适，越大过渡越快
TARGET_SLEW_RATE = 0.01

current_mode = MODE_DAMPING

TARGET_ANGLES = np.array([
    0.0,   0.5, -1.3,   # FL
    0.0,  -0.5,  1.3,   # FR
    0.0,  -0.6,  1.2,   # RR
    0.0,   0.6, -1.2,   # RL
])

Kp_stand = np.array([
    50.0, 50.0, 30.0,
    50.0, 50.0, 30.0,
    50.0, 50.0, 50.0,
    50.0, 50.0, 50.0,
])

Kd_stand = np.array([
    3.0, 3.0, 1.5,
    3.0, 3.0, 1.5,
    3.0, 3.0, 1.5,
    3.0, 3.0, 1.5,
])

Kd_damp  = 3.0      # 阻尼模式刹车强度


# ============================================================
#  1. 加载模型与数据
# ============================================================
MODEL_PATH = "black_description_pinkoptimization.xml"

model = mujoco.MjModel.from_xml_path(MODEL_PATH)
data  = mujoco.MjData(model)

locker = threading.Lock()


# ============================================================
#  2. 初始趴地姿态
# ============================================================
def init_prone_pose():
    data.qpos[0] = 0.0
    data.qpos[1] = 0.0
    data.qpos[2] = 0.45
    data.qpos[3:7] = [1.0, 0.0, 0.0, 0.0]

    data.qpos[7:19] = [
        0.0,  0.7, -1.6,   # FL
        0.0, -0.7,  1.6,   # FR
        0.0, -0.7,  1.6,   # RR
        0.0,  0.7, -1.6,   # RL
    ]
    mujoco.mj_forward(model, data)


init_prone_pose()
data.ctrl[:] = 0.0


# ============================================================
#  3. 输入方式一：MuJoCo 窗口按键回调
#     鼠标点一下仿真窗口后，按 空格 / S 即可
# ============================================================
def key_callback(keycode):
    global current_mode, stand_target
    if keycode == 32:
        current_mode = MODE_STAND
        stand_target = data.qpos[7:19].copy()    # ★ 从当前角度出发
        print(">>> 切换到【站立模式】")
    elif keycode == 83:
        current_mode = MODE_DAMPING
        print(">>> 切换到【阻尼模式】")


# ============================================================
#  4. 输入方式二：终端输入线程
#     在终端里输入“空行回车”= 站立，输入“s回车”= 阻尼
# ============================================================
def terminal_input_thread():
    global current_mode, stand_target
    while viewer.is_running():
        try:
            cmd = input().strip().lower()
            if cmd == "":
                current_mode = MODE_STAND
                stand_target = data.qpos[7:19].copy()    # ★ 同样初始化
                print(">>> 站立模式")
            elif cmd == "s":
                current_mode = MODE_DAMPING
                print(">>> 阻尼模式")
        except EOFError:
            break

# ============================================================
#  5. 线程函数
# ============================================================
def simulation_thread():
    global stand_target
    while viewer.is_running():
        step_start = time.perf_counter()

        with locker:
            q  = data.qpos[7:19]
            dq = data.qvel[6:18]

            if current_mode == MODE_DAMPING:
                data.ctrl[:] = -Kd_damp * dq
            elif current_mode == MODE_STAND:
                # ★ 目标向 TARGET_ANGLES 靠近一小步
                stand_target += (TARGET_ANGLES - stand_target) * TARGET_SLEW_RATE
                # ★ ctrl 用 stand_target 而不是 TARGET_ANGLES
                data.ctrl[:] = Kp_stand * (stand_target - q) - Kd_stand * dq

            mujoco.mj_step(model, data)
        
        elapsed = time.perf_counter() - step_start
        sleep_time = model.opt.timestep - elapsed
        if sleep_time > 0:
            time.sleep(sleep_time)


def viewer_thread():
    while viewer.is_running():
        with locker:
            viewer.sync()
        time.sleep(0.02)


# ============================================================
#  6. 主入口
# ============================================================
with mujoco.viewer.launch_passive(model, data) as viewer:
    viewer.key_callback = key_callback          # 绑定窗口按键

    time.sleep(0.2)

    sim_thread  = threading.Thread(target=simulation_thread,     daemon=True)
    vis_thread  = threading.Thread(target=viewer_thread,         daemon=True)
    in_thread   = threading.Thread(target=terminal_input_thread, daemon=True)

    sim_thread.start()
    vis_thread.start()
    in_thread.start()

    print("======================================================")
    print("操作说明：")
    print("  ① 用鼠标点击仿真窗口后，按 空格 = 站立，按 S = 阻尼")
    print("  ② 或在终端里直接按回车 = 站立，输入 s 再回车 = 阻尼")
    print("  关闭仿真窗口退出程序。")
    print("======================================================")

    sim_thread.join()
    vis_thread.join()
    in_thread.join()

print("仿真结束。")