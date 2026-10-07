// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dog_msgs:msg/ControllerCommand.idl
// generated code does not contain a copyright notice

#ifndef DOG_MSGS__MSG__DETAIL__CONTROLLER_COMMAND__STRUCT_H_
#define DOG_MSGS__MSG__DETAIL__CONTROLLER_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ControllerCommand in the package dog_msgs.
typedef struct dog_msgs__msg__ControllerCommand
{
  double kp[12];
  double kd[12];
  double q[12];
  double w[12];
  double tau[12];
} dog_msgs__msg__ControllerCommand;

// Struct for a sequence of dog_msgs__msg__ControllerCommand.
typedef struct dog_msgs__msg__ControllerCommand__Sequence
{
  dog_msgs__msg__ControllerCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dog_msgs__msg__ControllerCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOG_MSGS__MSG__DETAIL__CONTROLLER_COMMAND__STRUCT_H_
