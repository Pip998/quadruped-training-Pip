import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/pip/robocon/ROS2_training/dog_ros2_ws_with_js/install/node2_simulation'
