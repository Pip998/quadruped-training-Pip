// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dog_msgs:msg/ControllerCommand.idl
// generated code does not contain a copyright notice

#ifndef DOG_MSGS__MSG__DETAIL__CONTROLLER_COMMAND__BUILDER_HPP_
#define DOG_MSGS__MSG__DETAIL__CONTROLLER_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dog_msgs/msg/detail/controller_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dog_msgs
{

namespace msg
{

namespace builder
{

class Init_ControllerCommand_tau
{
public:
  explicit Init_ControllerCommand_tau(::dog_msgs::msg::ControllerCommand & msg)
  : msg_(msg)
  {}
  ::dog_msgs::msg::ControllerCommand tau(::dog_msgs::msg::ControllerCommand::_tau_type arg)
  {
    msg_.tau = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dog_msgs::msg::ControllerCommand msg_;
};

class Init_ControllerCommand_w
{
public:
  explicit Init_ControllerCommand_w(::dog_msgs::msg::ControllerCommand & msg)
  : msg_(msg)
  {}
  Init_ControllerCommand_tau w(::dog_msgs::msg::ControllerCommand::_w_type arg)
  {
    msg_.w = std::move(arg);
    return Init_ControllerCommand_tau(msg_);
  }

private:
  ::dog_msgs::msg::ControllerCommand msg_;
};

class Init_ControllerCommand_q
{
public:
  explicit Init_ControllerCommand_q(::dog_msgs::msg::ControllerCommand & msg)
  : msg_(msg)
  {}
  Init_ControllerCommand_w q(::dog_msgs::msg::ControllerCommand::_q_type arg)
  {
    msg_.q = std::move(arg);
    return Init_ControllerCommand_w(msg_);
  }

private:
  ::dog_msgs::msg::ControllerCommand msg_;
};

class Init_ControllerCommand_kd
{
public:
  explicit Init_ControllerCommand_kd(::dog_msgs::msg::ControllerCommand & msg)
  : msg_(msg)
  {}
  Init_ControllerCommand_q kd(::dog_msgs::msg::ControllerCommand::_kd_type arg)
  {
    msg_.kd = std::move(arg);
    return Init_ControllerCommand_q(msg_);
  }

private:
  ::dog_msgs::msg::ControllerCommand msg_;
};

class Init_ControllerCommand_kp
{
public:
  Init_ControllerCommand_kp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ControllerCommand_kd kp(::dog_msgs::msg::ControllerCommand::_kp_type arg)
  {
    msg_.kp = std::move(arg);
    return Init_ControllerCommand_kd(msg_);
  }

private:
  ::dog_msgs::msg::ControllerCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dog_msgs::msg::ControllerCommand>()
{
  return dog_msgs::msg::builder::Init_ControllerCommand_kp();
}

}  // namespace dog_msgs

#endif  // DOG_MSGS__MSG__DETAIL__CONTROLLER_COMMAND__BUILDER_HPP_
