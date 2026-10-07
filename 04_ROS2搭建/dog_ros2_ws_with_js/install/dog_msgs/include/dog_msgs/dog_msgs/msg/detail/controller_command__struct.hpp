// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dog_msgs:msg/ControllerCommand.idl
// generated code does not contain a copyright notice

#ifndef DOG_MSGS__MSG__DETAIL__CONTROLLER_COMMAND__STRUCT_HPP_
#define DOG_MSGS__MSG__DETAIL__CONTROLLER_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__dog_msgs__msg__ControllerCommand __attribute__((deprecated))
#else
# define DEPRECATED__dog_msgs__msg__ControllerCommand __declspec(deprecated)
#endif

namespace dog_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ControllerCommand_
{
  using Type = ControllerCommand_<ContainerAllocator>;

  explicit ControllerCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 12>::iterator, double>(this->kp.begin(), this->kp.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->kd.begin(), this->kd.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->q.begin(), this->q.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->w.begin(), this->w.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->tau.begin(), this->tau.end(), 0.0);
    }
  }

  explicit ControllerCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : kp(_alloc),
    kd(_alloc),
    q(_alloc),
    w(_alloc),
    tau(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 12>::iterator, double>(this->kp.begin(), this->kp.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->kd.begin(), this->kd.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->q.begin(), this->q.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->w.begin(), this->w.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->tau.begin(), this->tau.end(), 0.0);
    }
  }

  // field types and members
  using _kp_type =
    std::array<double, 12>;
  _kp_type kp;
  using _kd_type =
    std::array<double, 12>;
  _kd_type kd;
  using _q_type =
    std::array<double, 12>;
  _q_type q;
  using _w_type =
    std::array<double, 12>;
  _w_type w;
  using _tau_type =
    std::array<double, 12>;
  _tau_type tau;

  // setters for named parameter idiom
  Type & set__kp(
    const std::array<double, 12> & _arg)
  {
    this->kp = _arg;
    return *this;
  }
  Type & set__kd(
    const std::array<double, 12> & _arg)
  {
    this->kd = _arg;
    return *this;
  }
  Type & set__q(
    const std::array<double, 12> & _arg)
  {
    this->q = _arg;
    return *this;
  }
  Type & set__w(
    const std::array<double, 12> & _arg)
  {
    this->w = _arg;
    return *this;
  }
  Type & set__tau(
    const std::array<double, 12> & _arg)
  {
    this->tau = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dog_msgs::msg::ControllerCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const dog_msgs::msg::ControllerCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dog_msgs::msg::ControllerCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dog_msgs::msg::ControllerCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dog_msgs::msg::ControllerCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dog_msgs::msg::ControllerCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dog_msgs::msg::ControllerCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dog_msgs::msg::ControllerCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dog_msgs::msg::ControllerCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dog_msgs::msg::ControllerCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dog_msgs__msg__ControllerCommand
    std::shared_ptr<dog_msgs::msg::ControllerCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dog_msgs__msg__ControllerCommand
    std::shared_ptr<dog_msgs::msg::ControllerCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ControllerCommand_ & other) const
  {
    if (this->kp != other.kp) {
      return false;
    }
    if (this->kd != other.kd) {
      return false;
    }
    if (this->q != other.q) {
      return false;
    }
    if (this->w != other.w) {
      return false;
    }
    if (this->tau != other.tau) {
      return false;
    }
    return true;
  }
  bool operator!=(const ControllerCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ControllerCommand_

// alias to use template instance with default allocator
using ControllerCommand =
  dog_msgs::msg::ControllerCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dog_msgs

#endif  // DOG_MSGS__MSG__DETAIL__CONTROLLER_COMMAND__STRUCT_HPP_
