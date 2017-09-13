#include "franka/robot_state.h"

#include <algorithm>
#include <cstring>
#include <iterator>

namespace franka {

namespace {

template <class T, size_t N>
std::ostream& operator<<(std::ostream& ostream, const std::array<T, N>& array) {
  ostream << "[";
  std::copy(array.cbegin(), array.cend() - 1, std::ostream_iterator<T>(ostream, ","));
  std::copy(array.cend() - 1, array.cend(), std::ostream_iterator<T>(ostream));
  ostream << "]";
  return ostream;
}

std::ostream& operator<<(std::ostream& ostream, const RobotMode robot_mode) {
  ostream << "\"";
  switch (robot_mode) {
    case (RobotMode::kUserStopped):
      ostream << "User stopped";
      break;
    case (RobotMode::kIdle):
      ostream << "Idle";
      break;
    case (RobotMode::kMove):
      ostream << "Move";
      break;
    case (RobotMode::kGuiding):
      ostream << "Guiding";
      break;
    case (RobotMode::kReflex):
      ostream << "Reflex";
      break;
    case (RobotMode::kAutomaticErrorRecovery):
      ostream << "Automatic error recovery";
      break;
    case (RobotMode::kOther):
      ostream << "Other";
      break;
  }
  ostream << "\"";
  return ostream;
}

}  // anonymous namespace

std::ostream& operator<<(std::ostream& ostream, const franka::RobotState& robot_state) {
  ostream << "{\"O_T_EE\": " << robot_state.O_T_EE << ", \"O_T_EE_d\": " << robot_state.O_T_EE_d
          << ", \"F_T_EE\": " << robot_state.F_T_EE << ", \"EE_T_K\": " << robot_state.EE_T_K
          << ", \"m_load\": " << robot_state.m_load << ", \"F_x_Cload\": " << robot_state.F_x_Cload
          << ", \"I_load\": " << robot_state.I_load << ", \"elbow\": " << robot_state.elbow
          << ", \"elbow_d\": " << robot_state.elbow_d << ", \"tau_J\": " << robot_state.tau_J
          << ", \"dtau_J\": " << robot_state.dtau_J << ", \"q\": " << robot_state.q
          << ", \"dq\": " << robot_state.dq << ", \"q_d\": " << robot_state.q_d
          << ", \"dq_d\": " << robot_state.dq_d
          << ", \"joint_contact\": " << robot_state.joint_contact
          << ", \"cartesian_contact\": " << robot_state.cartesian_contact
          << ", \"joint_collision\": " << robot_state.joint_collision
          << ", \"cartesian_collision\": " << robot_state.cartesian_collision
          << ", \"tau_ext_hat_filtered\": " << robot_state.tau_ext_hat_filtered
          << ", \"O_F_ext_hat_K\": " << robot_state.O_F_ext_hat_K
          << ", \"K_F_ext_hat_K\": " << robot_state.K_F_ext_hat_K
          << ", \"current_errors\": " << robot_state.current_errors
          << ", \"last_motion_errors\": " << robot_state.last_motion_errors
          << ", \"control_command_success_rate\": " << robot_state.control_command_success_rate
          << ", \"robot_mode\": " << robot_state.robot_mode
          << ", \"time\": " << robot_state.time.toMSec() << "}";
  return ostream;
}

}  // namespace franka