// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dog_msgs:msg/MotorState.idl
// generated code does not contain a copyright notice

#ifndef DOG_MSGS__MSG__DETAIL__MOTOR_STATE__BUILDER_HPP_
#define DOG_MSGS__MSG__DETAIL__MOTOR_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dog_msgs/msg/detail/motor_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dog_msgs
{

namespace msg
{

namespace builder
{

class Init_MotorState_cur
{
public:
  explicit Init_MotorState_cur(::dog_msgs::msg::MotorState & msg)
  : msg_(msg)
  {}
  ::dog_msgs::msg::MotorState cur(::dog_msgs::msg::MotorState::_cur_type arg)
  {
    msg_.cur = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dog_msgs::msg::MotorState msg_;
};

class Init_MotorState_tau
{
public:
  explicit Init_MotorState_tau(::dog_msgs::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_cur tau(::dog_msgs::msg::MotorState::_tau_type arg)
  {
    msg_.tau = std::move(arg);
    return Init_MotorState_cur(msg_);
  }

private:
  ::dog_msgs::msg::MotorState msg_;
};

class Init_MotorState_ddq
{
public:
  explicit Init_MotorState_ddq(::dog_msgs::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_tau ddq(::dog_msgs::msg::MotorState::_ddq_type arg)
  {
    msg_.ddq = std::move(arg);
    return Init_MotorState_tau(msg_);
  }

private:
  ::dog_msgs::msg::MotorState msg_;
};

class Init_MotorState_dq
{
public:
  explicit Init_MotorState_dq(::dog_msgs::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_ddq dq(::dog_msgs::msg::MotorState::_dq_type arg)
  {
    msg_.dq = std::move(arg);
    return Init_MotorState_ddq(msg_);
  }

private:
  ::dog_msgs::msg::MotorState msg_;
};

class Init_MotorState_q
{
public:
  Init_MotorState_q()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorState_dq q(::dog_msgs::msg::MotorState::_q_type arg)
  {
    msg_.q = std::move(arg);
    return Init_MotorState_dq(msg_);
  }

private:
  ::dog_msgs::msg::MotorState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dog_msgs::msg::MotorState>()
{
  return dog_msgs::msg::builder::Init_MotorState_q();
}

}  // namespace dog_msgs

#endif  // DOG_MSGS__MSG__DETAIL__MOTOR_STATE__BUILDER_HPP_
