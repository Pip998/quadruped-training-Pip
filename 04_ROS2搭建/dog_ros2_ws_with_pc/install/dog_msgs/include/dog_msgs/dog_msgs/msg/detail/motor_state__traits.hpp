// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dog_msgs:msg/MotorState.idl
// generated code does not contain a copyright notice

#ifndef DOG_MSGS__MSG__DETAIL__MOTOR_STATE__TRAITS_HPP_
#define DOG_MSGS__MSG__DETAIL__MOTOR_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dog_msgs/msg/detail/motor_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace dog_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotorState & msg,
  std::ostream & out)
{
  out << "{";
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

  // member: dq
  {
    if (msg.dq.size() == 0) {
      out << "dq: []";
    } else {
      out << "dq: [";
      size_t pending_items = msg.dq.size();
      for (auto item : msg.dq) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: ddq
  {
    if (msg.ddq.size() == 0) {
      out << "ddq: []";
    } else {
      out << "ddq: [";
      size_t pending_items = msg.ddq.size();
      for (auto item : msg.ddq) {
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
    out << ", ";
  }

  // member: cur
  {
    if (msg.cur.size() == 0) {
      out << "cur: []";
    } else {
      out << "cur: [";
      size_t pending_items = msg.cur.size();
      for (auto item : msg.cur) {
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
  const MotorState & msg,
  std::ostream & out, size_t indentation = 0)
{
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

  // member: dq
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.dq.size() == 0) {
      out << "dq: []\n";
    } else {
      out << "dq:\n";
      for (auto item : msg.dq) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: ddq
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.ddq.size() == 0) {
      out << "ddq: []\n";
    } else {
      out << "ddq:\n";
      for (auto item : msg.ddq) {
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

  // member: cur
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.cur.size() == 0) {
      out << "cur: []\n";
    } else {
      out << "cur:\n";
      for (auto item : msg.cur) {
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

inline std::string to_yaml(const MotorState & msg, bool use_flow_style = false)
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
  const dog_msgs::msg::MotorState & msg,
  std::ostream & out, size_t indentation = 0)
{
  dog_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dog_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const dog_msgs::msg::MotorState & msg)
{
  return dog_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<dog_msgs::msg::MotorState>()
{
  return "dog_msgs::msg::MotorState";
}

template<>
inline const char * name<dog_msgs::msg::MotorState>()
{
  return "dog_msgs/msg/MotorState";
}

template<>
struct has_fixed_size<dog_msgs::msg::MotorState>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<dog_msgs::msg::MotorState>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<dog_msgs::msg::MotorState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DOG_MSGS__MSG__DETAIL__MOTOR_STATE__TRAITS_HPP_
