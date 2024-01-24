#include "assignment.h"
int pos = 0;

void initialize() {}

void disabled() {}

void competition_initialize() {}

void autonomous() {
  for (int i = 0; i < 4; i++) {
    drivetrain->moveDistance(6_in);
    drivetrain->turnAngle(90_deg);
  }
}

void opcontrol() {
  // Arm Controls
  ControllerButton armUpBtn(ControllerDigital::right);
  ControllerButton armDownBtn(ControllerDigital::down);

  // Wing Controls
  ControllerButton leftWingBtn(ControllerDigital::L2);
  ControllerButton rightWingBtn(ControllerDigital::R2);

  while (1) {
    drivetrain->getModel()->arcade(
        controller.getAnalog(ControllerAnalog::leftY),
        controller.getAnalog(ControllerAnalog::rightX));

    leftWing.set_value(leftWingBtn.isPressed());
    rightWing.set_value(rightWingBtn.isPressed());

    pos = (armUpBtn.changedToPressed()) ? pos + 1 : pos;
    pos = (armDownBtn.changedToPressed()) ? pos - 1 : pos;
    pos = (pos == 3 || pos < 0) ? 0: pos;
    armMtr.moveAbsolute(1700 * pos, 100);

    // int enable_flywheel = (pos == 0) ? 0 : 1;
    // flwMtr.moveVoltage(12000 * enable_flywheel);

    pros::delay(10);
  }
}
