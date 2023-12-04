#include "assignment.h"

void initialize() {}

void disabled() {}

void competition_initialize() {}

void autonomous() {
  for (int i = 0; i < 4; i++) {
    drivetrain->moveDistance(6_in);
    drivetrain->turnAngle(120_deg);
  }
}

void opcontrol() {
  while (1) {
    drivetrain->getModel()->arcade(
        controller.getAnalog(ControllerAnalog::leftY),
        controller.getAnalog(ControllerAnalog::rightX));

    pros::delay(10);
  }
}
