#include "main.h"

#ifndef ASSIGNMENT_H_
#define ASSIGNMENT_H_

/***************************/
/*********Controls**********/
/***************************/

// Arm Controls
extern ControllerButton armHomeBtn;
extern ControllerButton armMidBtn;
extern ControllerButton armEndBtn;

// Wing Controls
extern ControllerButton leftWingBtn;
extern ControllerButton rightWingBtn;

// 
extern ControllerButton flwBtn;

/***************************/
/*******Periphirals*********/
/***************************/
extern Controller controller;

extern std::shared_ptr<ChassisController> drivetrain;

extern Motor armMtr;
extern Motor flwMtr;
extern DistanceSensor dist;

extern pros::ADIDigitalOut leftWing;
extern pros::ADIDigitalOut rightWing;

#endif // ASSIGNMENT_H_
