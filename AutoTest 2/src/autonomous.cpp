#include "main.h"
/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */


void autonomous() {
  if(selector::auton == 1){
    // START (PICKUP)
    pros::delay(50); // small delay
    handToglle(2); // clamp the current block in hand
    pros::delay(200);
    armControl(-200);
    pros::delay(600);
    armControl(0);
    pros::delay(100);


    // MOVE AND STACK
    translate(905, 35); // move forward to mid line
    pros::delay(300);

    armControl(100);
    pros::delay(360);
    armControl(0);
    pros::delay(450);

    handToglle(1); // open the claw
    pros::delay(350);


    // CLAMP BOTH
    armControl(200);
    pros::delay(173);
    armControl(0);
    pros::delay(400);

    translate(350, 15);
    pros::delay(500);

    handToglle(2); // clamp the claw
    pros::delay(600);

    translate(-400, 15);
    pros::delay(150);

    // LIFT AND TURN

    armControl(-120);
    pros::delay(720);
    armControl(0);
    pros::delay(600);

    turnRight(340, 35);
    pros::delay(400);

    translate(580, 45);
    pros::delay(200);

    armControl(120); // arm down
    pros::delay(300);
    armControl(0);
    pros::delay(600);

    handToglle(1); // open clamp
    pros::delay(700);

    armControl(-100);
    pros::delay(310);
    armControl(0);
    pros::delay(300);


    // REVERSE AND SHUTDOWN
    translate(-500, 30); // move backward from tray
    pros::delay(300);
    handToglle(3); // set claw motor to NIL
    pros::delay(500);

  } else if(selector::auton == 2) {
    // START (PICKUP)
    pros::delay(50); // small delay
    handToglle(2); // clamp the current block in hand
    pros::delay(200);
    armControl(-200);
    pros::delay(600);
    armControl(0);
    pros::delay(100);


    // MOVE AND STACK
    translate(915, 35); // move forward to mid line
    pros::delay(300);

    armControl(100);
    pros::delay(360);
    armControl(0);
    pros::delay(350);

    handToglle(1); // open the claw
    pros::delay(350);


    // CLAMP BOTH
    armControl(200);
    pros::delay(173);
    armControl(0);
    pros::delay(400);

    translate(350, 15);
    pros::delay(500);

    handToglle(2); // clamp the claw
    pros::delay(600);

    translate(-400, 15);
    pros::delay(150);

    // LIFT AND TURN

    armControl(-120);
    pros::delay(720);
    armControl(0);
    pros::delay(600);

    turnLeft(515, 35);
    pros::delay(400);

    translate(720, 45);
    pros::delay(200);

    armControl(120); // arm down
    pros::delay(300);
    armControl(0);
    pros::delay(600);

    handToglle(1); // open clamp
    pros::delay(700);

    armControl(-100);
    pros::delay(310);
    armControl(0);
    pros::delay(300);


    // REVERSE AND SHUTDOWN
    translate(-500, 30); // move backward from tray
    pros::delay(300);
    handToglle(3); // set claw motor to NIL
    pros::delay(500);
  }
}
