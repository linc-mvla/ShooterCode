#pragma once

#include <ctre/Phoenix.h>

#include "Util/Mechanism.h"
#include "ShuffleboardSender/ShuffleboardSender.h"

class Flywheel : public Mechanism{
    public:
        enum class State{
            IDLE,
            RAMPING,
            AT_TARGET
        };

        Flywheel(std::string name, bool enabled = true, bool shuffleboard = false);

        void SetTarget(double vel);

        State GetState();
        bool AtTarget();

    private:
        void CoreTeleopPeriodic() override;

        void CoreShuffleboardInit() override;
        void CoreShuffleboardPeriodic() override;
        void CoreShuffleboardUpdate() override;

        WPI_TalonFX motor_;

        State state_;

        ShuffleboardSender shuff_;
};