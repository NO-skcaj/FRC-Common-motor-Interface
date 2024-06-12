#include "../motors/../motors/../motors/../motors/../motors/TalonFX.hpp"

using namespace CIM;

namespace
{

/// @brief creates the actual motor
TalonFX(int CAN)
{
  // Actual motor
  this->motor = ctre::pheonix6::hardware::TalonFX{CAN, "rio"};
}

/// @brief does config, most just so happens to be PID
void Config(float P, float I, float D, int max_voltage)
{
  configs::TalonFXConfiguration talonFXConfigs{};

  // set slot 0 gains and leave every other config factory-default
  configs::Slot0Configs& slot0Configs = talonFXConfigs.Slot0;
  slot0Configs.kP = 0.11;
  slot0Configs.kI = 0.5;
  slot0Configs.kD = 0.001;

  // apply all configs, 50 ms total timeout
  m_talonFX.GetConfigurator().Apply(talonFXConfigs, 50_ms);
}

/// @brief does config, most just so happens to be PIDV
void Config(float P, float I, float D, float V, int max_voltage)
{
  configs::TalonFXConfiguration talonFXConfigs{};

  // set slot 0 gains and leave every other config factory-default
  configs::Slot0Configs& slot0Configs = talonFXConfigs.Slot0;
  slot0Configs.kV = V;
  slot0Configs.kP = P;
  slot0Configs.kI = I;
  slot0Configs.kD = D;

  // apply all configs, 50 ms total timeout
  motor.GetConfigurator().Apply(talonFXConfigs, 50_ms);
}

/// @brief gets a CANcoder bc they are great
void GetEncoder(int CAN)
{
  this->encoder = ctre::phoenix6::hardware::CANcoder(CAN, "rio");
}

/// @brief puts input (1, -1) to motor
void SetSpeed(double input)
{
  motor.Set(input);
}


void SetAngle(float angle)
{
  motor.Set(this->angleController.Calculate(angle));
}

/// @brief just the current set speed
/// @returns last setSpeed() input -1.0 - 1
double GetSpeed()
{
  return motor.Get();
}


double GetAngle()
{
  return ;
}

/// @brief Get the total distance in rotation counts from the Encoder
double GetDistance()
{
  
}

}
