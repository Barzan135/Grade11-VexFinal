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
    translate(920, 35); // move forward to mid line
    pros::delay(300);

    armControl(100);
    pros::delay(360);
    armControl(0);
    pros::delay(600);

    handToglle(1); // open the claw
    pros::delay(500);


    // CLAMP BOTH
    armControl(200);
    pros::delay(170);
    armControl(0);
    pros::delay(600);

    translate(350, 15);
    pros::delay(600);

    handToglle(2); // clamp the claw
    pros::delay(700);


    // HERE ADD THE THIRD BLOCK PICKUP
    armControl(-200);
    pros::delay(800);
    armControl(0);
    pros::delay(150);

    translate(430, 15); // move forward a bit
    pros::delay(100);

    armControl(100); // move claw down a little bit to connect with 3rd block
    pros::delay(665);
    armControl(0);
    pros::delay(1200);


    handToglle(1); // open hand
    pros::delay(400);

    armControl(100); // claw down to clamp blocks
    pros::delay(170);
    armControl(0);
    pros::delay(400);

    translate(470, 15); // once hand is moved move back to original position to clamp
    pros::delay(300);

    handToglle(2); // clamp blocks
    pros::delay(400);


    // LIFT AND TURN

    armControl(-120);
    pros::delay(720);
    armControl(0);
    pros::delay(600);

    turnRight(523, 35);
    pros::delay(400);

    // MOVE TO TRAY, PLACEMENT
    translate(780, 35); // move forward
    pros::delay(200);


    armControl(120); // arm down
    pros::delay(300);
    armControl(0);
    pros::delay(600);

    handToglle(1); // open clamp
    pros::delay(1000);

    armControl(-100);
    pros::delay(310);
    armControl(0);
    pros::delay(300);


    // REVERSE AND SHUTDOWN
    translate(-500, 30); // move backward from tray
    pros::delay(300);
    handToglle(3); // set claw motor to NIL


    pros::delay(400);
    turnRight(520, 35);

    pros::delay(200);
    translate(1400, 40);
    pros::delay(300);

    translate(-30, 40);
    pros::delay(400);

    handToglle(2);
    clawArm = -200;
    translate(3000, 50);
    pros::delay(10000);

  } else if(selector::auton == 2) {

    // START (PICKUP)
    pros::delay(50); // small delay
    handToglle(2); // clamp the current block in hand

    clawArm = -200; // move the hand up
    pros::delay(600);
    clawArm = 0; // stop the movement
    pros::delay(100);

    // moves and stacks block
    translate(905, 45); // move forward to mid line
    pros::delay(100);

    clawArm = 200; // clawn down onto second block
    pros::delay(300);
    clawArm = 0; // stop movement
    pros::delay(100);

    handToglle(1); // open the claw

    // clamp both blocks
    clawArm = 200; // move claw down
    pros::delay(115);
    clawArm = 0; // stop movement
    pros::delay(200);

    translate(390, 15); // move forward
    pros::delay(200);

    handToglle(2); // clamp the claw
    pros::delay(150);


    // HERE ADD THE THIRD BLOCK PICKUP
    clawArm = - 200; // start by lifting two previously lifted blocks
    pros::delay(1000);
    clawArm = 0; // stop motor after 1 second
    pros::delay(150);

    translate(200, 15); // move forward a bit

    pros::delay(100);

    clawArm = 200; // move claw down a little bit to connect with 3rd block
    pros::delay(500);
    clawArm = 0;
    pros::delay(100);

    handToglle(1); // open hand
    pros::delay(100);
    translate(-100, 15); // move back
    pros::delay(100);

    clawArm = 200; // claw down to clamp blocks
    pros::delay(500);
    clawArm = 0;
    pros::delay(100);

    translate(100, 15); // once hand is moved move back to original position to clamp
    pros::delay(100);

    handToglle(2); // clamp blocks
    pros::delay(200);

    // LIFT AND TURN
    turnLeft(450, 35);
    pros::delay(100);

    clawArm = - 120;
    pros::delay(1500);
    clawArm = 0;
    pros::delay(100);

    // MOVE TO TRAY, PLACEMENT
    translate(600, 35); // move forward
    pros::delay(100);

    clawArm = 120; // claw down
    pros::delay(750);
    clawArm = 0; // stop movement
    pros::delay(200);

    handToglle(1); // open clamp
    pros::delay(200);

    // REVERSE AND SHUTDOWN
    translate(-400, 30); // move backward from tray
    pros::delay(300);
    handToglle(3); // set claw motor to NIL
  }
}
