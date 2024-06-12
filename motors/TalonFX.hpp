#pragma once

#include "../baseMotor.hpp"

namespace CMI
{
class TalonFX
{
  public:
    TalonFX(P, I, D);
    TalonFX(P, I, D, S, V); // weird thing that CTRE has in their docs, not super sure, but they seem to use it
    // Configs
    void SetPID()        override;
    // Set commands aka power the motor
    void SetSpeed()      override; // Will go through PID
    void SetAngle()      override;
    // Get commands aka telemetry
    double GetSpeed()    override;
    double GetAngle()    override;
    double GetDistance() override;
}
} // CMI
