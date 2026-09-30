#include <unistd.h>
#include <iostream>
#include <string>
#include <cmath>
#include "serialPort/SerialPort.h"
#include "unitreeMotor/unitreeMotor.h"

int main() {
  SerialPort serial("/dev/ttyUSB0");
  MotorCmd  cmd;
  MotorData data;

  const float GEAR = queryGearRatio(MotorType::GO_M8010_6);
  const float KP   = 0.60;   // 刚度
  const float KD   = 0.20;   // 阻尼
  const int   SEND_HZ_US = 2500;  // 2.5ms/帧
  const int   MOVE_STEPS = 600;   // 1.5秒走完
  const float offset = 0.9926;    
                              // 1个零点 0.9926
                              // 2个零点 1.9852
                              // 3个零点 2.9778
                              // 4个零点 3.9704
                              // 5个零点 4.9630
                              // 6个零点 5.9556

  std::cout << "GEAR = " << GEAR << std::endl;

  cmd.motorType = MotorType::GO_M8010_6;
  data.motorType = MotorType::GO_M8010_6;
  cmd.id   = 0;
  cmd.mode = queryMotorMode(MotorType::GO_M8010_6, MotorMode::FOC);
  cmd.kp   = KP;
  cmd.kd   = KD;
  cmd.dq   = 0.0;
  cmd.tau  = 0.0;

  // ---------- 1) 读取上电位置 ----------
  std::cout << "Reading power-on position..." << std::endl;
  cmd.kp  = 0.0;
  cmd.kd  = 0.0;
  cmd.q   = 0.0;
  cmd.dq  = 0.0;
  cmd.tau = 0.0;
  serial.sendRecv(&cmd, &data);

  float q_power_on = data.q;
  std::cout << "q_power_on = " << q_power_on
            << " (raw rad) = " << q_power_on * 180.0 / M_PI << " deg (rotor side)"
            << " = " << q_power_on / GEAR * 180.0 / M_PI << " deg (output side)"
            << std::endl;

  // ---------- 2) 回零:内部读数 0 点 ----------
  std::cout << "Moving to INTERNAL ZERO (cmd.q = 0)..." << std::endl;
  cmd.kp  = KP;
  cmd.kd  = KD;
  cmd.q   = 0.0 - offset;          // 直接回内部 0 点 - 偏移
  cmd.dq  = 0.0;
  cmd.tau = 0.0;

  for (int i = 0; i < MOVE_STEPS; i++) {
    serial.sendRecv(&cmd, &data);
    usleep(SEND_HZ_US);
  }

  std::cout << "At internal zero. data.q = " << data.q
            << "  (should be ~0)" << std::endl;
  // ---------- 3) 键盘循环 ----------
  std::string input;
  while (true) {
    std::cout << "\nEnter angle in degrees (e.g. 30)"
              << " | 's' = STOP (disable)"
              << " | 'q' = quit: ";
    std::cin >> input;

    // ---- 停止/失能 ----
    if (input == "s") {
      std::cout << "STOP: disabling motor." << std::endl;
      cmd.mode = queryMotorMode(MotorType::GO_M8010_6, MotorMode::FOC);
      cmd.kp   = 0.0;
      cmd.kd   = 0.0;
      cmd.q    = 0.0;
      cmd.dq   = 0.0;
      cmd.tau  = 0.0;
      for (int i = 0; i < 50; i++) {
        serial.sendRecv(&cmd, &data);
        usleep(SEND_HZ_US);
      }
      std::cout << "Motor disabled." << std::endl;
      continue;
    }

    // ---- 退出程序 ----
    if (input == "q") {
      std::cout << "Quit. Disabling motor before exit." << std::endl;
      cmd.kp  = 0.0;
      cmd.kd  = 0.0;
      cmd.tau = 0.0;
      for (int i = 0; i < 50; i++) {
        serial.sendRecv(&cmd, &data);
        usleep(SEND_HZ_US);
      }
      break;
    }

    // ---- 数字：转角度 ----
    float angle_deg  = std::stof(input);
    float target_rad = angle_deg * M_PI / 180.0;

    cmd.mode = queryMotorMode(MotorType::GO_M8010_6, MotorMode::FOC);
    cmd.kp   = KP;
    cmd.kd   = KD;
    cmd.q    = (target_rad - offset) * GEAR ;  // 下发减 offset
    cmd.dq   = 0.0;
    cmd.tau  = 0.0;

    std::cout << "Moving to " << angle_deg << " degree." << std::endl;
    for (int i = 0; i < MOVE_STEPS; i++) {
      serial.sendRecv(&cmd, &data);
      usleep(SEND_HZ_US);
    }

    float q_joint = data.q / GEAR + offset;   // 读取加 offset
    std::cout << "Reached. current q = " << q_joint * 180.0 / M_PI
              << "  temp = " << data.temp
              << "  W = " << data.dq << std::endl;
  }
  return 0;
}