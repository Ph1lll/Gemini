#include "assignment.h"

void armControl() {
  int pos = 0;
  bool calibrated = false;
  bool enable_flywheel = 0;
  while (1) {
    if (!calibrated) {
      armMtr.moveVoltage(-6000);
      controller.setText(0, 0, std::to_string(armMtr.getCurrentDraw()));
      if (armMtr.getCurrentDraw() >= 1250) {
        armMtr.tarePosition();
        calibrated = true;
      }
    } else {
      pos = (armUpBtn.changedToPressed()) ? pos + 1 : pos;
      pos = (armDownBtn.changedToPressed()) ? pos - 1 : pos;
      pos = (pos == 3 || pos < 0) ? 0: pos;
      armMtr.moveAbsolute(2250 * pos, 100);

      if (flwBtn.changedToPressed()) enable_flywheel = (enable_flywheel == 0) ? 1 : 0;
      flwMtr.moveVoltage(12000 * enable_flywheel);
    }
    pros::delay(10);
  }
}

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
  pros::Task armcontrol(armControl);
  while (1) {
    drivetrain->getModel()->arcade(
        controller.getAnalog(ControllerAnalog::leftY),
        controller.getAnalog(ControllerAnalog::rightX));

    leftWing.set_value(leftWingBtn.isPressed());
    rightWing.set_value(rightWingBtn.isPressed());

    pros::delay(10);
  }
}
