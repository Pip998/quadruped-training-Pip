// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dog_msgs:srv/HandleCommand.idl
// generated code does not contain a copyright notice

#ifndef DOG_MSGS__SRV__DETAIL__HANDLE_COMMAND__STRUCT_HPP_
#define DOG_MSGS__SRV__DETAIL__HANDLE_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__dog_msgs__srv__HandleCommand_Request __attribute__((deprecated))
#else
# define DEPRECATED__dog_msgs__srv__HandleCommand_Request __declspec(deprecated)
#endif

namespace dog_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct HandleCommand_Request_
{
  using Type = HandleCommand_Request_<ContainerAllocator>;

  explicit HandleCommand_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = 0l;
    }
  }

  explicit HandleCommand_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = 0l;
    }
  }

  // field types and members
  using _command_type =
    int32_t;
  _command_type command;

  // setters for named parameter idiom
  Type & set__command(
    const int32_t & _arg)
  {
    this->command = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dog_msgs::srv::HandleCommand_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const dog_msgs::srv::HandleCommand_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dog_msgs::srv::HandleCommand_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dog_msgs::srv::HandleCommand_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dog_msgs::srv::HandleCommand_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dog_msgs::srv::HandleCommand_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dog_msgs::srv::HandleCommand_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dog_msgs::srv::HandleCommand_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dog_msgs::srv::HandleCommand_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dog_msgs::srv::HandleCommand_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dog_msgs__srv__HandleCommand_Request
    std::shared_ptr<dog_msgs::srv::HandleCommand_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dog_msgs__srv__HandleCommand_Request
    std::shared_ptr<dog_msgs::srv::HandleCommand_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HandleCommand_Request_ & other) const
  {
    if (this->command != other.command) {
      return false;
    }
    return true;
  }
  bool operator!=(const HandleCommand_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HandleCommand_Request_

// alias to use template instance with default allocator
using HandleCommand_Request =
  dog_msgs::srv::HandleCommand_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace dog_msgs


#ifndef _WIN32
# define DEPRECATED__dog_msgs__srv__HandleCommand_Response __attribute__((deprecated))
#else
# define DEPRECATED__dog_msgs__srv__HandleCommand_Response __declspec(deprecated)
#endif

namespace dog_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct HandleCommand_Response_
{
  using Type = HandleCommand_Response_<ContainerAllocator>;

  explicit HandleCommand_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit HandleCommand_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dog_msgs::srv::HandleCommand_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const dog_msgs::srv::HandleCommand_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dog_msgs::srv::HandleCommand_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dog_msgs::srv::HandleCommand_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dog_msgs::srv::HandleCommand_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dog_msgs::srv::HandleCommand_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dog_msgs::srv::HandleCommand_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dog_msgs::srv::HandleCommand_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dog_msgs::srv::HandleCommand_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dog_msgs::srv::HandleCommand_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dog_msgs__srv__HandleCommand_Response
    std::shared_ptr<dog_msgs::srv::HandleCommand_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dog_msgs__srv__HandleCommand_Response
    std::shared_ptr<dog_msgs::srv::HandleCommand_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HandleCommand_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const HandleCommand_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HandleCommand_Response_

// alias to use template instance with default allocator
using HandleCommand_Response =
  dog_msgs::srv::HandleCommand_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace dog_msgs

namespace dog_msgs
{

namespace srv
{

struct HandleCommand
{
  using Request = dog_msgs::srv::HandleCommand_Request;
  using Response = dog_msgs::srv::HandleCommand_Response;
};

}  // namespace srv

}  // namespace dog_msgs

#endif  // DOG_MSGS__SRV__DETAIL__HANDLE_COMMAND__STRUCT_HPP_
