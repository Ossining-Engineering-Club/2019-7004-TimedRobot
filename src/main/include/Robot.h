#pragma once

#include <string>
#include "frc/WPILib.h"
#include <frc/smartdashboard/SmartDashboard.h>
using namespace frc;

class Robot : public frc::TimedRobot {
 public:
  SmartDashboard *smartDashboard;
  
  Joystick stick1{0}; //left
  Joystick stick2{1}; //right
  Joystick stick3{2}; //arm

  Spark m_left{0};
  Spark m_right{1};
  Spark m_updown{3};

  Talon wheels{2};



  
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
};
