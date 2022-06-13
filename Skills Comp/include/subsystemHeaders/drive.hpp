#include "main.h"

//HELPER FUNCTIONS
void setDrive(int left, int right);

//DRIVER CONTROL FUNCTIONS
void setDriveMotors();

void reset_Drive_Encoders();
double avgDriveEncoer();

// AUTO PILOT
void translate(int units, int voltage);
void GoToWall(int voltage);

void turnRight(int turns, int voltage);
void turnLeft(int turns, int voltage);
