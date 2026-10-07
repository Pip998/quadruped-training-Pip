// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dog_msgs:msg/ControllerCommand.idl
// generated code does not contain a copyright notice

#ifndef DOG_MSGS__MSG__DETAIL__CONTROLLER_COMMAND__TRAITS_HPP_
#define DOG_MSGS__MSG__DETAIL__CONTROLLER_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dog_msgs/msg/detail/controller_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace dog_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ControllerCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: kp
  {
    if (msg.kp.size() == 0) {
      out << "kp: []";
    } else {
      out << "kp: [";
      size_t pending_items = msg.kp.size();
      for (auto item : msg.kp) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: kd
  {
    if (msg.kd.size() == 0) {
      out << "kd: []";
    } else {
      out << "kd: [";
      size_t pending_items = msg.kd.size();
      for (auto item : msg.kd) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: q
  {
    if (msg.q.size() == 0) {
      out << "q: []";
    } else {
      out << "q: [";
      size_t pending_items = msg.q.size();
      for (auto item : msg.q) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: w
  {
    if (msg.w.size() == 0) {
      out << "w: []";
    } else {
      out << "w: [";
      size_t pending_items = msg.w.size();
      for (auto item : msg.w) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: tau
  {
    if (msg.tau.size() == 0) {
      out << "tau: []";
    } else {
      out << "tau: [";
      size_t pending_items = msg.tau.size();
      for (auto item : msg.tau) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ControllerCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: kp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.kp.size() == 0) {
      out << "kp: []\n";
    } else {
      out << "kp:\n";
      for (auto item : msg.kp) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: kd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.kd.size() == 0) {
      out << "kd: []\n";
    } else {
      out << "kd:\n";
      for (auto item : msg.kd) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: q
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.q.size() == 0) {
      out << "q: []\n";
    } else {
      out << "q:\n";
      for (auto item : msg.q) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: w
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.w.size() == 0) {
      out << "w: []\n";
    } else {
      out << "w:\n";
      for (auto item : msg.w) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: tau
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.tau.size() == 0) {
      out << "tau: []\n";
    } else {
      out << "tau:\n";
      for (auto item : msg.tau) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ControllerCommand & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace dog_msgs

namespace rosidl_generator_traits
{

[[deprecated("use dog_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const dog_msgs::msg::ControllerCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  dog_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dog_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const dog_msgs::msg::ControllerCommand & msg)
{
  return dog_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<dog_msgs::msg::ControllerCommand>()
{
  return "dog_msgs::msg::ControllerCommand";
}

template<>
inline const char * name<dog_msgs::msg::ControllerCommand>()
{
  return "dog_msgs/msg/ControllerCommand";
}

template<>
struct has_fixed_size<dog_msgs::msg::ControllerCommand>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<dog_msgs::msg::ControllerCommand>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<dog_msgs::msg::ControllerCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DOG_MSGS__MSG__DETAIL__CONTROLLER_COMMAND__TRAITS_HPP_
