Most motors basically the exact same thing, so we should be able to create a common interface (class) that we can use to interact with them. So you could have a class that would be able to get/set the speed and angle, and get the distance. It would also implement PID (and velocity PID)

Common Motor Interface (CMI)
Goals:
Make CTRE easy
Make Rev the same as CTRE
Implement:
* PID
* Set
 - Speed
 - Angle
* Get
 - Speed
 - Angle
 - Distance
* Per brand config - not super sure how I want to do this

Something basic I want to be able to do is have a bunch of motors with associated encoders and be able to use the same functions regardless of brand.
Example for TalonFX
```cpp
// *** TalonFX Config
configs::TalonFXConfiguration talonFXConfigs{};

// set slot 0 gains and leave every other config factory-default
configs::Slot0Configs& slot0Configs = talonFXConfigs.Slot0;
slot0Configs.kP = 0.11;
slot0Configs.kI = 0.5;
slot0Configs.kD = 0.001;
// ***

CMI::Talonfx motor1{MotorID, EncoderID}; // Motor initialization
motor1.SetConfig(talonFXConfigs);	      // Config 
motor1.SetPID(P, I, D);

units::degree_t motorAngle{motor1.GetAngle()};
```

[WORK IN PROGRESS]
