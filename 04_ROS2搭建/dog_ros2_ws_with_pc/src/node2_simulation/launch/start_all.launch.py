import os
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    # node1
    node1_controller = Node(
        package='node1_controller',
        executable='node1_controller',
        name='node1_controller',
        output='screen',
        emulate_tty=True,
    )

    # node2
    node2_simulation = Node(
        package='node2_simulation',
        executable='node2_simulation',
        name='node2_simulation',
        output='screen',
        emulate_tty=True,
    )

    # node3
    node3_handle = Node(
        package='node3_handle',
        executable='node3_handle',
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