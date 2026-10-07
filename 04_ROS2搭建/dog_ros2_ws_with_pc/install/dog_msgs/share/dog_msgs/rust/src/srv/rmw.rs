#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "dog_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__dog_msgs__srv__HandleCommand_Request() -> *const std::ffi::c_void;
}

#[link(name = "dog_msgs__rosidl_generator_c")]
extern "C" {
    fn dog_msgs__srv__HandleCommand_Request__init(msg: *mut HandleCommand_Request) -> bool;
    fn dog_msgs__srv__HandleCommand_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<HandleCommand_Request>, size: usize) -> bool;
    fn dog_msgs__srv__HandleCommand_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<HandleCommand_Request>);
    fn dog_msgs__srv__HandleCommand_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<HandleCommand_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<HandleCommand_Request>) -> bool;
}

// Corresponds to dog_msgs__srv__HandleCommand_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HandleCommand_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub command: i32,

}



impl Default for HandleCommand_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !dog_msgs__srv__HandleCommand_Request__init(&mut msg as *mut _) {
        panic!("Call to dog_msgs__srv__HandleCommand_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for HandleCommand_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dog_msgs__srv__HandleCommand_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dog_msgs__srv__HandleCommand_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dog_msgs__srv__HandleCommand_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for HandleCommand_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for HandleCommand_Request where Self: Sized {
  const TYPE_NAME: &'static str = "dog_msgs/srv/HandleCommand_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__dog_msgs__srv__HandleCommand_Request() }
  }
}


#[link(name = "dog_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__dog_msgs__srv__HandleCommand_Response() -> *const std::ffi::c_void;
}

#[link(name = "dog_msgs__rosidl_generator_c")]
extern "C" {
    fn dog_msgs__srv__HandleCommand_Response__init(msg: *mut HandleCommand_Response) -> bool;
    fn dog_msgs__srv__HandleCommand_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<HandleCommand_Response>, size: usize) -> bool;
    fn dog_msgs__srv__HandleCommand_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<HandleCommand_Response>);
    fn dog_msgs__srv__HandleCommand_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<HandleCommand_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<HandleCommand_Response>) -> bool;
}

// Corresponds to dog_msgs__srv__HandleCommand_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HandleCommand_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for HandleCommand_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !dog_msgs__srv__HandleCommand_Response__init(&mut msg as *mut _) {
        panic!("Call to dog_msgs__srv__HandleCommand_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for HandleCommand_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dog_msgs__srv__HandleCommand_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dog_msgs__srv__HandleCommand_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dog_msgs__srv__HandleCommand_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for HandleCommand_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for HandleCommand_Response where Self: Sized {
  const TYPE_NAME: &'static str = "dog_msgs/srv/HandleCommand_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__dog_msgs__srv__HandleCommand_Response() }
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


