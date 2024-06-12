#pragma once

namespace CMI
{
class baseMotor
{
  public:
    // Initializaiton
    // baseMotor();
    // Configs
    // Ideally most config will be done here with per-brand configs, but will be eventually changed to out own config type
    void SetPID(); 
    void GetEncoder();
    // Set commands aka power the motor
    void SetSpeed(); // Will go through PID
    void SetAngle();
    // Get commands aka telemetry
    double GetSpeed();
    double GetAngle();
    double GetDistance();
  private:
    // PID values
    float P, I, D, S, V, A, G;
    // Etc
    int CANID = 0;

};
} // CMI
