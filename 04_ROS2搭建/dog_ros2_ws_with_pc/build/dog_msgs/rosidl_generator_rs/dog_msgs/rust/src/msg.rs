#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to dog_msgs__msg__ControllerCommand

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ControllerCommand::default())
  }
}

impl rosidl_runtime_rs::Message for ControllerCommand {
  type RmwMsg = super::msg::rmw::ControllerCommand;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        kp: msg.kp,
        kd: msg.kd,
        q: msg.q,
        w: msg.w,
        tau: msg.tau,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        kp: msg.kp,
        kd: msg.kd,
        q: msg.q,
        w: msg.w,
        tau: msg.tau,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      kp: msg.kp,
      kd: msg.kd,
      q: msg.q,
      w: msg.w,
      tau: msg.tau,
    }
  }
}


// Corresponds to dog_msgs__msg__MotorState

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::MotorState::default())
  }
}

impl rosidl_runtime_rs::Message for MotorState {
  type RmwMsg = super::msg::rmw::MotorState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        q: msg.q,
        dq: msg.dq,
        ddq: msg.ddq,
        tau: msg.tau,
        cur: msg.cur,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        q: msg.q,
        dq: msg.dq,
        ddq: msg.ddq,
        tau: msg.tau,
        cur: msg.cur,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      q: msg.q,
      dq: msg.dq,
      ddq: msg.ddq,
      tau: msg.tau,
      cur: msg.cur,
    }
  }
}


