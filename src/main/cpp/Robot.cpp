#include "Robot.h"

#include <iostream>
#include <frc/Timer.h>
#include <frc/smartdashboard/SmartDashboard.h>
using namespace frc;

void Robot::RobotInit() {

    
  /*m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);*/
}

/**
 * This function is called evePry robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
 /* m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  std::cout << "Auto selected: " << m_autoSelected << std::endl;

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }*/
}

void Robot::AutonomousPeriodic() {
  /*if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }*/
}

void Robot::TeleopInit() {}
frc::Relay visionlight(0, frc::Relay::Direction::kForwardOnly);
void Robot::TeleopPeriodic() {
       while(IsOperatorControl() && IsEnabled()) {
         if (stick2.GetRawButton(2) ){
             m_left.Set(-0.65*stick2.GetY());
             m_right.Set(-0.79*stick2.GetY());
             m_updown.Set(0.65*stick3.GetY()); //arm controls
             visionlight.Set(frc::Relay::Value::kOn);
         }
         else {

            m_left.Set(-0.65*stick1.GetY()); //left wheels
            m_right.Set(-0.79*stick2.GetY()); //right wheels
            m_updown.Set(0.65*stick3.GetY()); //arm controls
            visionlight.Set(frc::Relay::Value::kOn);
            while(stick3.GetRawButton(1)) { //arm wheels
                if (stick3.GetRawButton(2)) {
                    wheels.Set(0.99); //outake
                }
                else {
                    wheels.Set(-0.25); //intake
                }
              }
         }
       }
}
void Robot::TestPeriodic (){};
int main () {
  return 0;
}
#ifndef RUNNING_FRC_TESTS

#endif
