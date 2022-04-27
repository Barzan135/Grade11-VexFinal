#include "main.h"

void armControl(int power){
  clawArm = power;
}

void setClawArmMotor(){
  int ClawArmPower = 80 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) -  controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1));
  armControl(ClawArmPower);
}


