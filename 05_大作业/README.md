环境配置：libtorch，

目前有两个version，工作空间即/version_1或者/version2

version1是能跑通的版本，但需要手动创建三个节点，在handle终端键入1是趴下，2是站立，3是直走，0是停止，q是退出。

version2在1代上优化，将直行速度调的好看了点；并且新建了launch文件，可以直接在终端中source完环境直接用ros2 launch node2_simulation start_all.launch.py来启动。

期望3代能解决reset后卡地里弹飞的问题。。。
