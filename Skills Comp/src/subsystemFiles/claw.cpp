#include "main.h"

void armControl(int power){
  clawArm = -power;
  clawArm2 = power;
}


void translateArmMotor(int units, int power){
  clawArm.tare_position();
  clawArm2.tare_position();
  while(clawArm.get_position() < abs(units)){
    armControl(power);
    pros::delay(10);
  }
  armControl(0);
}

void setClawArmMotor(){
  int ClawArmPower = 80 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) -  controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1));
  armControl(ClawArmPower);
}
