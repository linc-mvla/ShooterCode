// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/TimedRobot.h>

#include "FFAutotuner/FFAutotuner.h"

#include "ShuffleboardSender/ShuffleboardSender.h"

#include "Shooter/Flywheel.h"

class Robot : public frc::TimedRobot {
  public:
    void RobotInit() override;
    void RobotPeriodic() override;

    void AutonomousInit() override;
    void AutonomousPeriodic() override;

    void TeleopInit() override;
    void TeleopPeriodic() override;

    void DisabledInit() override;
    void DisabledPeriodic() override;

    void TestInit() override;
    void TestPeriodic() override;

    void SimulationInit() override;
    void SimulationPeriodic() override;
  private:
    //Flywheel Testing
    Flywheel flywheel_{"Flywheel", true, true};

    FFAutotuner flywheelTuner_{"FlywheelTuner", FFAutotuner::SIMPLE, 0.0, 6.18, 0.5, 1.0};
    bool isTuning_;

    ShuffleboardSender shuff_;
};
