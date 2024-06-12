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
CMI::Talonfx motor1{MotorID, EncoderID}; // Motor initialization
motor1.Config(P, I, D, max_voltage);	      // Config

units::degree_t motorAngle{motor1.GetAngle()};
```

[WORK IN PROGRESS]
