# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target dog_msgs::dog_msgs
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${dog_msgs_TARGETS}.
if(dog_msgs_TARGETS AND NOT TARGET dog_msgs::dog_msgs)
  add_library(dog_msgs::dog_msgs INTERFACE IMPORTED)
  set_target_properties(dog_msgs::dog_msgs PROPERTIES
    INTERFACE_LINK_LIBRARIES "${dog_msgs_TARGETS}")
endif()
