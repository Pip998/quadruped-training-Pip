// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dog_msgs:srv/HandleCommand.idl
// generated code does not contain a copyright notice

#ifndef DOG_MSGS__SRV__DETAIL__HANDLE_COMMAND__STRUCT_H_
#define DOG_MSGS__SRV__DETAIL__HANDLE_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/HandleCommand in the package dog_msgs.
typedef struct dog_msgs__srv__HandleCommand_Request
{
  int32_t command;
} dog_msgs__srv__HandleCommand_Request;

// Struct for a sequence of dog_msgs__srv__HandleCommand_Request.
typedef struct dog_msgs__srv__HandleCommand_Request__Sequence
{
  dog_msgs__srv__HandleCommand_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dog_msgs__srv__HandleCommand_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/HandleCommand in the package dog_msgs.
typedef struct dog_msgs__srv__HandleCommand_Response
{
  bool success;
} dog_msgs__srv__HandleCommand_Response;

// Struct for a sequence of dog_msgs__srv__HandleCommand_Response.
typedef struct dog_msgs__srv__HandleCommand_Response__Sequence
{
  dog_msgs__srv__HandleCommand_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dog_msgs__srv__HandleCommand_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOG_MSGS__SRV__DETAIL__HANDLE_COMMAND__STRUCT_H_
