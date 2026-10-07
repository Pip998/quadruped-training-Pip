// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dog_msgs:srv/HandleCommand.idl
// generated code does not contain a copyright notice

#ifndef DOG_MSGS__SRV__DETAIL__HANDLE_COMMAND__BUILDER_HPP_
#define DOG_MSGS__SRV__DETAIL__HANDLE_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dog_msgs/srv/detail/handle_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dog_msgs
{

namespace srv
{

namespace builder
{

class Init_HandleCommand_Request_command
{
public:
  Init_HandleCommand_Request_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::dog_msgs::srv::HandleCommand_Request command(::dog_msgs::srv::HandleCommand_Request::_command_type arg)
  {
    msg_.command = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dog_msgs::srv::HandleCommand_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dog_msgs::srv::HandleCommand_Request>()
{
  return dog_msgs::srv::builder::Init_HandleCommand_Request_command();
}

}  // namespace dog_msgs


namespace dog_msgs
{

namespace srv
{

namespace builder
{

class Init_HandleCommand_Response_success
{
public:
  Init_HandleCommand_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::dog_msgs::srv::HandleCommand_Response success(::dog_msgs::srv::HandleCommand_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dog_msgs::srv::HandleCommand_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dog_msgs::srv::HandleCommand_Response>()
{
  return dog_msgs::srv::builder::Init_HandleCommand_Response_success();
}

}  // namespace dog_msgs

#endif  // DOG_MSGS__SRV__DETAIL__HANDLE_COMMAND__BUILDER_HPP_
