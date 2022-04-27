#include "main.h"

void opcontrol() {
   while (true)  {  // While true loops run constantly
    setDriveMotors(); // Runs the motor functions
    setLiftMotors(); // Runs Lift Motor functions
    setClawArmMotor();
    setClawHandMotor();
    pros::delay(10); //  delays the code for 10 seconds, so it alligns with the motors delay
  }
}
