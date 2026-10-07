因为没有Xbox手柄，故分为了两个文件夹。第一个js后缀是理论上需要用用Xbox手柄调试的工作空间，无法只通过pc端运行，第二个pc后缀是把手柄输出的内容改为键入指令，在本机终端上即可运行。

通信示意：

node1_controller为控制器，通过【话题topic】的自定义消息类型(dog_msgs)向node2_simulation发送5*12的电机控制矩阵；也通过【服务service】的消息类型与node3_handle通信，接受趴卧/站立的指令并给出callback。

node2_simulation为仿真，通过【话题topic】的自定义消息类型(dog_msgs)向node1_controller返回5*12的电机状态矩阵，同时也用ros2自带的sensor_imu向node1_controller返回imu数据。（不过仿真程序给不出来角加速度和电流数据...）

node3_handle为手柄/键盘，通过【服务service】的消息类型向node1_controller发送站立/趴卧指令并接收callback。

【以上为第一代版本，运行前需要source一下环境，再逐个开启终端运行三个节点】



【以下为第二代版本说明，两个工作空间都添加了launch的功能，因为用python写的，所以运行的时候需要在终端里source一下环境，再执行ros2 launch node2_simulation start_all.launch.py即可】

这样在js后缀文件夹中依旧无法通过Xbox来操控（因为没有手柄），但在pc后缀文件夹中就可以在自动弹出的新终端窗口里键入1/2操控机器狗趴卧/站立了！！




