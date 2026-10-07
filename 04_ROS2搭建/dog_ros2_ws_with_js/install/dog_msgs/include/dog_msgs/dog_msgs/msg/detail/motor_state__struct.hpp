// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dog_msgs:msg/MotorState.idl
// generated code does not contain a copyright notice

#ifndef DOG_MSGS__MSG__DETAIL__MOTOR_STATE__STRUCT_HPP_
#define DOG_MSGS__MSG__DETAIL__MOTOR_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__dog_msgs__msg__MotorState __attribute__((deprecated))
#else
# define DEPRECATED__dog_msgs__msg__MotorState __declspec(deprecated)
#endif

namespace dog_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorState_
{
  using Type = MotorState_<ContainerAllocator>;

  explicit MotorState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 12>::iterator, double>(this->q.begin(), this->q.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->dq.begin(), this->dq.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->ddq.begin(), this->ddq.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->tau.begin(), this->tau.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->cur.begin(), this->cur.end(), 0.0);
    }
  }

  explicit MotorState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : q(_alloc),
    dq(_alloc),
    ddq(_alloc),
    tau(_alloc),
    cur(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 12>::iterator, double>(this->q.begin(), this->q.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->dq.begin(), this->dq.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->ddq.begin(), this->ddq.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->tau.begin(), this->tau.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->cur.begin(), this->cur.end(), 0.0);
    }
  }

  // field types and members
  using _q_type =
    std::array<double, 12>;
  _q_type q;
  using _dq_type =
    std::array<double, 12>;
  _dq_type dq;
  using _ddq_type =
    std::array<double, 12>;
  _ddq_type ddq;
  using _tau_type =
    std::array<double, 12>;
  _tau_type tau;
  using _cur_type =
    std::array<double, 12>;
  _cur_type cur;

  // setters for named parameter idiom
  Type & set__q(
    const std::array<double, 12> & _arg)
  {
    this->q = _arg;
    return *this;
  }
  Type & set__dq(
    const std::array<double, 12> & _arg)
  {
    this->dq = _arg;
    return *this;
  }
  Type & set__ddq(
    const std::array<double, 12> & _arg)
  {
    this->ddq = _arg;
    return *this;
  }
  Type & set__tau(
    const std::array<double, 12> & _arg)
  {
    this->tau = _arg;
    return *this;
  }
  Type & set__cur(
    const std::array<double, 12> & _arg)
  {
    this->cur = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dog_msgs::msg::MotorState_<ContainerAllocator> *;
  using ConstRawPtr =
    const dog_msgs::msg::MotorState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dog_msgs::msg::MotorState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dog_msgs::msg::MotorState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dog_msgs::msg::MotorState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dog_msgs::msg::MotorState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dog_msgs::msg::MotorState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dog_msgs::msg::MotorState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dog_msgs::msg::MotorState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dog_msgs::msg::MotorState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dog_msgs__msg__MotorState
    std::shared_ptr<dog_msgs::msg::MotorState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dog_msgs__msg__MotorState
    std::shared_ptr<dog_msgs::msg::MotorState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorState_ & other) const
  {
    if (this->q != other.q) {
      return false;
    }
    if (this->dq != other.dq) {
      return false;
    }
    if (this->ddq != other.ddq) {
      return false;
    }
    if (this->tau != other.tau) {
      return false;
    }
    if (this->cur != other.cur) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorState_

// alias to use template instance with default allocator
using MotorState =
  dog_msgs::msg::MotorState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dog_msgs

#endif  // DOG_MSGS__MSG__DETAIL__MOTOR_STATE__STRUCT_HPP_
