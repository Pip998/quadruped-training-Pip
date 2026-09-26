cmake_minimum_required(VERSION 3.16)
project(laying_dog_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ★ MuJoCo 根目录（包含 bin/include/lib/model/sample/simulate/wasm 的那一层）
set(MUJOCO_DIR "/home/pip/robocon/mujoco_training/00_mujoco_c++")

# 头文件目录
set(MUJOCO_INCLUDE_DIR "${MUJOCO_DIR}/include")

# 库文件（动态库）
set(MUJOCO_LIBRARY "${MUJOCO_DIR}/lib/libmujoco.so")

# 依赖库：GLFW + OpenGL（可视化必需）
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

# 加入 MuJoCo 头文件搜索路径
include_directories(${MUJOCO_INCLUDE_DIR})

# 声明可执行文件
add_executable(laying_dog simulate_laying_dog.cpp)

# 链接 MuJoCo、GLFW、OpenGL
target_link_libraries(laying_dog PRIVATE
    ${MUJOCO_LIBRARY}
    glfw
    OpenGL::GL
)

# 确保程序运行时能找到 libmujoco.so
set_target_properties(laying_dog PROPERTIES
    BUILD_RPATH "${MUJOCO_DIR}/lib"
)