// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from dog_msgs:msg/ControllerCommand.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "dog_msgs/msg/detail/controller_command__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace dog_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ControllerCommand_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) dog_msgs::msg::ControllerCommand(_init);
}

void ControllerCommand_fini_function(void * message_memory)
{
  auto typed_message = static_cast<dog_msgs::msg::ControllerCommand *>(message_memory);
  typed_message->~ControllerCommand();
}

size_t size_function__ControllerCommand__kp(const void * untyped_member)
{
  (void)untyped_member;
  return 12;
}

const void * get_const_function__ControllerCommand__kp(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void * get_function__ControllerCommand__kp(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void fetch_function__ControllerCommand__kp(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__ControllerCommand__kp(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__ControllerCommand__kp(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__ControllerCommand__kp(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__ControllerCommand__kd(const void * untyped_member)
{
  (void)untyped_member;
  return 12;
}

const void * get_const_function__ControllerCommand__kd(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void * get_function__ControllerCommand__kd(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void fetch_function__ControllerCommand__kd(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__ControllerCommand__kd(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__ControllerCommand__kd(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__ControllerCommand__kd(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__ControllerCommand__q(const void * untyped_member)
{
  (void)untyped_member;
  return 12;
}

const void * get_const_function__ControllerCommand__q(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void * get_function__ControllerCommand__q(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void fetch_function__ControllerCommand__q(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__ControllerCommand__q(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__ControllerCommand__q(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__ControllerCommand__q(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__ControllerCommand__w(const void * untyped_member)
{
  (void)untyped_member;
  return 12;
}

const void * get_const_function__ControllerCommand__w(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void * get_function__ControllerCommand__w(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void fetch_function__ControllerCommand__w(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__ControllerCommand__w(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__ControllerCommand__w(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__ControllerCommand__w(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__ControllerCommand__tau(const void * untyped_member)
{
  (void)untyped_member;
  return 12;
}

const void * get_const_function__ControllerCommand__tau(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void * get_function__ControllerCommand__tau(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void fetch_function__ControllerCommand__tau(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__ControllerCommand__tau(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__ControllerCommand__tau(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__ControllerCommand__tau(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ControllerCommand_message_member_array[5] = {
  {
    "kp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    12,  // array size
    false,  // is upper bound
    offsetof(dog_msgs::msg::ControllerCommand, kp),  // bytes offset in struct
    nullptr,  // default value
    size_function__ControllerCommand__kp,  // size() function pointer
    get_const_function__ControllerCommand__kp,  // get_const(index) function pointer
    get_function__ControllerCommand__kp,  // get(index) function pointer
    fetch_function__ControllerCommand__kp,  // fetch(index, &value) function pointer
    assign_function__ControllerCommand__kp,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "kd",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    12,  // array size
    false,  // is upper bound
    offsetof(dog_msgs::msg::ControllerCommand, kd),  // bytes offset in struct
    nullptr,  // default value
    size_function__ControllerCommand__kd,  // size() function pointer
    get_const_function__ControllerCommand__kd,  // get_const(index) function pointer
    get_function__ControllerCommand__kd,  // get(index) function pointer
    fetch_function__ControllerCommand__kd,  // fetch(index, &value) function pointer
    assign_function__ControllerCommand__kd,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "q",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    12,  // array size
    false,  // is upper bound
    offsetof(dog_msgs::msg::ControllerCommand, q),  // bytes offset in struct
    nullptr,  // default value
    size_function__ControllerCommand__q,  // size() function pointer
    get_const_function__ControllerCommand__q,  // get_const(index) function pointer
    get_function__ControllerCommand__q,  // get(index) function pointer
    fetch_function__ControllerCommand__q,  // fetch(index, &value) function pointer
    assign_function__ControllerCommand__q,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "w",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    12,  // array size
    false,  // is upper bound
    offsetof(dog_msgs::msg::ControllerCommand, w),  // bytes offset in struct
    nullptr,  // default value
    size_function__ControllerCommand__w,  // size() function pointer
    get_const_function__ControllerCommand__w,  // get_const(index) function pointer
    get_function__ControllerCommand__w,  // get(index) function pointer
    fetch_function__ControllerCommand__w,  // fetch(index, &value) function pointer
    assign_function__ControllerCommand__w,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "tau",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    12,  // array size
    false,  // is upper bound
    offsetof(dog_msgs::msg::ControllerCommand, tau),  // bytes offset in struct
    nullptr,  // default value
    size_function__ControllerCommand__tau,  // size() function pointer
    get_const_function__ControllerCommand__tau,  // get_const(index) function pointer
    get_function__ControllerCommand__tau,  // get(index) function pointer
    fetch_function__ControllerCommand__tau,  // fetch(index, &value) function pointer
    assign_function__ControllerCommand__tau,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ControllerCommand_message_members = {
  "dog_msgs::msg",  // message namespace
  "ControllerCommand",  // message name
  5,  // number of fields
  sizeof(dog_msgs::msg::ControllerCommand),
  ControllerCommand_message_member_array,  // message members
  ControllerCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  ControllerCommand_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ControllerCommand_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ControllerCommand_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace dog_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<dog_msgs::msg::ControllerCommand>()
{
  return &::dog_msgs::msg::rosidl_typesupport_introspection_cpp::ControllerCommand_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, dog_msgs, msg, ControllerCommand)() {
  return &::dog_msgs::msg::rosidl_typesupport_introspection_cpp::ControllerCommand_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
