// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

void Robot::RobotInit() {
  shuff_.add("Auto Tune", &isTuning_, {5,5,0,0}, true);
}

void Robot::RobotPeriodic() {
  flywheel_.Periodic();
  shuff_.update(true);
}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
  if(isTuning_){
    flywheelTuner_.setPose(flywheel_.GetPose());
    double volts = flywheelTuner_.getVoltage();
    flywheel_.SetVoltage(volts);
  }
  flywheel_.TeleopPeriodic();
}

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}
void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
