// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dog_msgs:srv/HandleCommand.idl
// generated code does not contain a copyright notice

#ifndef DOG_MSGS__SRV__DETAIL__HANDLE_COMMAND__TRAITS_HPP_
#define DOG_MSGS__SRV__DETAIL__HANDLE_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dog_msgs/srv/detail/handle_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace dog_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const HandleCommand_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: command
  {
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HandleCommand_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: command
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HandleCommand_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace dog_msgs

namespace rosidl_generator_traits
{

[[deprecated("use dog_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const dog_msgs::srv::HandleCommand_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  dog_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dog_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const dog_msgs::srv::HandleCommand_Request & msg)
{
  return dog_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dog_msgs::srv::HandleCommand_Request>()
{
  return "dog_msgs::srv::HandleCommand_Request";
}

template<>
inline const char * name<dog_msgs::srv::HandleCommand_Request>()
{
  return "dog_msgs/srv/HandleCommand_Request";
}

template<>
struct has_fixed_size<dog_msgs::srv::HandleCommand_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<dog_msgs::srv::HandleCommand_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<dog_msgs::srv::HandleCommand_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace dog_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const HandleCommand_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HandleCommand_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HandleCommand_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace dog_msgs

namespace rosidl_generator_traits
{

[[deprecated("use dog_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const dog_msgs::srv::HandleCommand_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  dog_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dog_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const dog_msgs::srv::HandleCommand_Response & msg)
{
  return dog_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dog_msgs::srv::HandleCommand_Response>()
{
  return "dog_msgs::srv::HandleCommand_Response";
}

template<>
inline const char * name<dog_msgs::srv::HandleCommand_Response>()
{
  return "dog_msgs/srv/HandleCommand_Response";
}

template<>
struct has_fixed_size<dog_msgs::srv::HandleCommand_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<dog_msgs::srv::HandleCommand_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<dog_msgs::srv::HandleCommand_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<dog_msgs::srv::HandleCommand>()
{
  return "dog_msgs::srv::HandleCommand";
}

template<>
inline const char * name<dog_msgs::srv::HandleCommand>()
{
  return "dog_msgs/srv/HandleCommand";
}

template<>
struct has_fixed_size<dog_msgs::srv::HandleCommand>
  : std::integral_constant<
    bool,
    has_fixed_size<dog_msgs::srv::HandleCommand_Request>::value &&
    has_fixed_size<dog_msgs::srv::HandleCommand_Response>::value
  >
{
};

template<>
struct has_bounded_size<dog_msgs::srv::HandleCommand>
  : std::integral_constant<
    bool,
    has_bounded_size<dog_msgs::srv::HandleCommand_Request>::value &&
    has_bounded_size<dog_msgs::srv::HandleCommand_Response>::value
  >
{
};

template<>
struct is_service<dog_msgs::srv::HandleCommand>
  : std::true_type
{
};

template<>
struct is_service_request<dog_msgs::srv::HandleCommand_Request>
  : std::true_type
{
};

template<>
struct is_service_response<dog_msgs::srv::HandleCommand_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DOG_MSGS__SRV__DETAIL__HANDLE_COMMAND__TRAITS_HPP_
