import os
from launch import LaunchDescription
from launch.actions import ExecuteProcess
from launch_ros.actions import Node

def generate_launch_description():
#  ws_root = os.path.expanduser(
# '~/robocon/ROS2_training/03_walking_dog/version2')
    # node1
    node1_controller = Node(
        package='node1_controller',
        executable='controller',
        name='node1_controller',
        output='screen',
        emulate_tty=True,
    )

    # node2
    node2_simulation = Node(
        package='node2_simulation',
        executable='simulation',
        name='node2_simulation',
        output='screen',
        emulate_tty=True,
    )

    # node3
    node3_handle = Node(
        package='node3_handle',
        executable='handle',
        name='node3_handle',
        output='screen',
        emulate_tty=True,
        # 这里用 gnome-terminal -- 来启动新窗口
        prefix='gnome-terminal --',
    )
    
    return LaunchDescription([
        node1_controller,
        node2_simulation,
        node3_handle,
    ])