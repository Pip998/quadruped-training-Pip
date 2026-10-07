#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to dog_msgs__srv__HandleCommand_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HandleCommand_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub command: i32,

}



impl Default for HandleCommand_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::HandleCommand_Request::default())
  }
}

impl rosidl_runtime_rs::Message for HandleCommand_Request {
  type RmwMsg = super::srv::rmw::HandleCommand_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        command: msg.command,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      command: msg.command,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      command: msg.command,
    }
  }
}


// Corresponds to dog_msgs__srv__HandleCommand_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HandleCommand_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for HandleCommand_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::HandleCommand_Response::default())
  }
}

impl rosidl_runtime_rs::Message for HandleCommand_Response {
  type RmwMsg = super::srv::rmw::HandleCommand_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
    }
  }
}






#[link(name = "dog_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__dog_msgs__srv__HandleCommand() -> *const std::ffi::c_void;
}

// Corresponds to dog_msgs__srv__HandleCommand
#[allow(missing_docs, non_camel_case_types)]
pub struct HandleCommand;

impl rosidl_runtime_rs::Service for HandleCommand {
    type Request = HandleCommand_Request;
    type Response = HandleCommand_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__dog_msgs__srv__HandleCommand() }
    }
}


