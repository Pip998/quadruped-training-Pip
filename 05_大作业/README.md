一、工程说明

目前有三个version，工作空间即/version1或2或3。

version1是能跑通的版本，但需要手动创建三个节点，在handle终端键入1是趴下，2是站立，3是直走，0是停止，q是退出。

version2在1代上优化，调整直行速度；并且新建了launch文件，可以直接在终端中source完环境直接用ros2 launch node2_simulation start_all.launch.py来启动。

version3在2代的基础上优化，修改了xml文件中的机器狗初始高度，使其在mujoco窗口里【reset】后能够正常出现在坐标原点；并且新增后退/左转/右转运动模式，运动自由度更高。

二、环境配置：libtorch

1.安装以下的ros依赖包：

bash:

sudo apt install ros-$ROS_DISTRO-teleop-twist-keyboard ros-$ROS_DISTRO-ros2-control ros-$ROS_DISTRO-ros2-controllers ros-$ROS_DISTRO-control-toolbox ros-$ROS_DISTRO-robot-state-publisher ros-$ROS_DISTRO-joint-state-publisher-gui ros-$ROS_DISTRO-gazebo-ros2-control ros-$ROS_DISTRO-gazebo-ros-pkgs ros-$ROS_DISTRO-xacro


2.在任意位置下载并部署`libtorch`（请修改下面的 **\<YOUR_PATH\>** 为实际路径）

bash:

cd <YOUR_PATH>
wget https://download.pytorch.org/libtorch/cpu/libtorch-cxx11-abi-shared-with-deps-2.0.1%2Bcpu.zip
unzip libtorch-cxx11-abi-shared-with-deps-2.0.1+cpu.zip -d ./
echo 'export Torch_DIR=<YOUR_PATH>/libtorch' >> ~/.bashrc
source ~/.bashrc

3.安装`yaml-cpp`和`lcm`

bash:

sudo apt install liblcm-dev libyaml-cpp-dev

4.找到controller的CmakeLists，修改rl_policy.cpp的路径；打开.bash，检查Torch（即libtorch）的路径是否与下载的一致。

