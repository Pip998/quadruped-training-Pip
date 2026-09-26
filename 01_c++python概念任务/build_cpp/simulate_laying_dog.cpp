#include <mujoco/mujoco.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <cstring>

// ============================================================
//  全局变量
// ============================================================
mjModel* model = nullptr;
mjData*  data  = nullptr;
std::mutex locker;
bool running = true;
GLFWwindow* window = nullptr;

// ============================================================
//  模拟线程函数
// ============================================================
void simulation_thread() {
    while (running) {
        auto start = std::chrono::steady_clock::now();

        {
            std::lock_guard<std::mutex> guard(locker);
            // 所有关节力矩设为 0
            for (int i = 0; i < model->nu; ++i) {
                data->ctrl[i] = 0.0;
            }
            mj_step(model, data);
        }

        auto end = std::chrono::steady_clock::now();
        double elapsed = std::chrono::duration<double>(end - start).count();
        double sleep_time = model->opt.timestep - elapsed;
        if (sleep_time > 0) {
            std::this_thread::sleep_for(std::chrono::duration<double>(sleep_time));
        }
    }
}

// ============================================================
//  主函数
// ============================================================
int main() {
    // --------------------------------------------------------
    // 1. 初始化 GLFW
    // --------------------------------------------------------
    if (!glfwInit()) {
        std::cerr << "GLFW 初始化失败" << std::endl;
        return -1;
    }

    // --------------------------------------------------------
    // 2. 加载模型
    // --------------------------------------------------------
    char error[1000] = "";
    model = mj_loadXML("black_description_optimization.xml", nullptr, error, 1000);
    if (!model) {
        std::cerr << "模型加载失败: " << error << std::endl;
        glfwTerminate();
        return -1;
    }
    data = mj_makeData(model);

    // --------------------------------------------------------
    // 3. 设置初始趴地姿态
    // --------------------------------------------------------
    data->qpos[0] = 0.0;
    data->qpos[1] = 0.0;
    data->qpos[2] = 0.45;
    data->qpos[3] = 1.0;
    data->qpos[4] = 0.0;
    data->qpos[5] = 0.0;
    data->qpos[6] = 0.0;

    double joints[12] = {
        0.0,  0.7, -1.6,   // FL
        0.0, -0.7,  1.6,   // FR
        0.0, -0.7,  1.6,   // RR
        0.0,  0.7, -1.6    // RL
    };
    for (int i = 0; i < 12; ++i) {
        data->qpos[7 + i] = joints[i];
    }
    mj_forward(model, data);

    // --------------------------------------------------------
    // 4. 创建可视化窗口
    // --------------------------------------------------------
    window = glfwCreateWindow(1200, 900, "Laying Dog Simulation", nullptr, nullptr);
    if (!window) {
        std::cerr << "窗口创建失败" << std::endl;
        mj_deleteData(data);
        mj_deleteModel(model);
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);   // 开启垂直同步，避免画面撕裂

    // --------------------------------------------------------
    // 5. 初始化 MuJoCo 可视化对象
    //    （必须在 OpenGL 上下文创建之后）
    // --------------------------------------------------------
    mjvCamera camera;
    mjvOption option;
    mjvScene  scene;
    mjrContext context;

    mjv_defaultCamera(&camera);
    mjv_defaultOption(&option);
    mjv_defaultScene(&scene);
    mjr_defaultContext(&context);

    // 创建场景（maxgeom 给一个足够大的值）
    mjv_makeScene(model, &scene, 2000);

    // 创建 GPU 渲染上下文（字体大小可调）
    mjr_makeContext(model, &context, mjFONTSCALE_150);

    // 设置初始相机视角（可自行调整）
    camera.lookat[0] = 0.0;
    camera.lookat[1] = 0.0;
    camera.lookat[2] = 0.15;   // 看向狗身体中下部
    camera.distance  = 1.2;    // 距离
    camera.azimuth   = 90.0;   // 水平环绕角
    camera.elevation = -20.0;  // 俯视角

    // --------------------------------------------------------
    // 6. 启动模拟线程
    // --------------------------------------------------------
    std::thread sim_thread(simulation_thread);

    // --------------------------------------------------------
    // 7. 主循环：渲染 + 交互
    // --------------------------------------------------------
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // 获取当前窗口的帧缓冲尺寸
        mjrRect viewport = {0, 0, 0, 0};
        glfwGetFramebufferSize(window, &viewport.width, &viewport.height);

        {
            std::lock_guard<std::mutex> guard(locker);

            // 用最新的物理状态更新场景
            mjv_updateScene(model, data, &option, nullptr,
                            &camera, mjCAT_ALL, &scene);

            // 渲染场景到当前 OpenGL 帧缓冲
            mjr_render(viewport, &scene, &context);
        }

        // 交换前后缓冲，把画面显示出来
        glfwSwapBuffers(window);

        // 控制渲染帧率，约 60 FPS
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    // --------------------------------------------------------
    // 8. 清理资源
    // --------------------------------------------------------
    running = false;
    sim_thread.join();

    mjr_freeContext(&context);
    mjv_freeScene(&scene);

    mj_deleteData(data);
    mj_deleteModel(model);

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}