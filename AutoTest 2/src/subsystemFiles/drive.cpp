#include "main.h"

// HELPER FUNCTIONS
void setDrive(int left, int right) {
  driveLeftBack = left;
  driveRightBack = right;
  driveLeftFront = left;
  driveRightFront = right;
}

void reset_Drive_Encoders() {
  // reset motor encoder
  driveLeftBack.tare_position();
  driveRightBack.tare_position();
  driveLeftFront.tare_position();
  driveRightFront.tare_position();

  // reset shaft encoder
  encoder1.reset();
  encoder1.reset();
}

double avgDriveEncoder(){
  return abs(encoder1.get_value()) +
         abs(encoder2.get_value()) / 2;
}

//DRIVER CONTROL FUNCTIONS
void setDriveMotors() {
  int leftJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  int rightJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  setDrive(leftJoystick, rightJoystick);
}

// AUTO PILOT
void translate(int units, int voltage){
  // define direction
 int direction = abs(units) / units; // either 1 or -1
  // reset the motor encoders
  reset_Drive_Encoders();
  // drive forward until units are reached
  while(avgDriveEncoder() < abs(units)) {
    setDrive(voltage * direction, voltage * direction);
    pros::delay(10);
  }
  // brief brake
 setDrive(-10 * direction, -10 * direction);
 pros::delay(50);
  //set drive back to neutral
 setDrive(0,0);
}

