#include "main.h"

void handToglle(int value){
  if (value == 1) {
    clawHand = -80;
  } else if (value == 2){
    clawHand = 80;
  } else if (value == 3) {
    clawHand = 0;
  }
}

void setClawHandMotor(){
  if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)){
    handToglle(1);
  }else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)){
    handToglle(2);
  }else if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)){
    handToglle(3);
  }
}
