#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "dog_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__dog_msgs__msg__ControllerCommand() -> *const std::ffi::c_void;
}

#[link(name = "dog_msgs__rosidl_generator_c")]
extern "C" {
    fn dog_msgs__msg__ControllerCommand__init(msg: *mut ControllerCommand) -> bool;
    fn dog_msgs__msg__ControllerCommand__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ControllerCommand>, size: usize) -> bool;
    fn dog_msgs__msg__ControllerCommand__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ControllerCommand>);
    fn dog_msgs__msg__ControllerCommand__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ControllerCommand>, out_seq: *mut rosidl_runtime_rs::Sequence<ControllerCommand>) -> bool;
}

// Corresponds to dog_msgs__msg__ControllerCommand
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ControllerCommand {

    // This member is not documented.
    #[allow(missing_docs)]
    pub kp: [f64; 12],


    // This member is not documented.
    #[allow(missing_docs)]
    pub kd: [f64; 12],


    // This member is not documented.
    #[allow(missing_docs)]
    pub q: [f64; 12],


    // This member is not documented.
    #[allow(missing_docs)]
    pub w: [f64; 12],


    // This member is not documented.
    #[allow(missing_docs)]
    pub tau: [f64; 12],

}



impl Default for ControllerCommand {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !dog_msgs__msg__ControllerCommand__init(&mut msg as *mut _) {
        panic!("Call to dog_msgs__msg__ControllerCommand__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ControllerCommand {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dog_msgs__msg__ControllerCommand__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dog_msgs__msg__ControllerCommand__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dog_msgs__msg__ControllerCommand__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ControllerCommand {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ControllerCommand where Self: Sized {
  const TYPE_NAME: &'static str = "dog_msgs/msg/ControllerCommand";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__dog_msgs__msg__ControllerCommand() }
  }
}


#[link(name = "dog_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__dog_msgs__msg__MotorState() -> *const std::ffi::c_void;
}

#[link(name = "dog_msgs__rosidl_generator_c")]
extern "C" {
    fn dog_msgs__msg__MotorState__init(msg: *mut MotorState) -> bool;
    fn dog_msgs__msg__MotorState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MotorState>, size: usize) -> bool;
    fn dog_msgs__msg__MotorState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MotorState>);
    fn dog_msgs__msg__MotorState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MotorState>, out_seq: *mut rosidl_runtime_rs::Sequence<MotorState>) -> bool;
}

// Corresponds to dog_msgs__msg__MotorState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MotorState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub q: [f64; 12],


    // This member is not documented.
    #[allow(missing_docs)]
    pub dq: [f64; 12],


    // This member is not documented.
    #[allow(missing_docs)]
    pub ddq: [f64; 12],


    // This member is not documented.
    #[allow(missing_docs)]
    pub tau: [f64; 12],


    // This member is not documented.
    #[allow(missing_docs)]
    pub cur: [f64; 12],

}



impl Default for MotorState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !dog_msgs__msg__MotorState__init(&mut msg as *mut _) {
        panic!("Call to dog_msgs__msg__MotorState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MotorState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dog_msgs__msg__MotorState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dog_msgs__msg__MotorState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dog_msgs__msg__MotorState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MotorState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MotorState where Self: Sized {
  const TYPE_NAME: &'static str = "dog_msgs/msg/MotorState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__dog_msgs__msg__MotorState() }
  }
}


