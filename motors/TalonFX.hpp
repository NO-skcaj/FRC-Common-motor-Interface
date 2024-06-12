#pragma once

#include "../baseMotor.hpp"

namespace CMI
{
class TalonFX
{
  public:
    // Hardware Initialization
    TalonFX();
    TalonFX(); 
    void GetEncoder()       override;
    // Configs
    void Config(float P, float I, float D, int max_voltage)          override;
    void Config(float P, float I, float D, float V, int max_voltage) override; // weird thing that CTRE has in their docs, not super sure, but they seem to use it
    // Set commands aka power the motor
    void SetSpeed()         override; // Will go through PID
    void SetAngle()         override;
    // Get commands aka telemetry
    double GetSpeed()       override;
    double GetAngle()       override;
    double GetDistance()    override;
  private:
    ctre::phoenix6::hardware::TalonFX  motor  {0, "rio"};
    ctre::phoenix6::hardware::CANcoder encoder(0, "rio");
    
    frc::PIDcontroller angleController{1, 0, 0};
    turningPidController.EnableContinuousInput(-3.14159, 3.14159);
};
} // CMI
