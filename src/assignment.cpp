#include "assignment.h"

/***************************/
/*********Controls**********/
/***************************/

// Arm Controls
ControllerButton armUpBtn(ControllerDigital::right);
ControllerButton armDownBtn(ControllerDigital::down);

// Wing Controls
ControllerButton leftWingBtn(ControllerDigital::L2);
ControllerButton rightWingBtn(ControllerDigital::R2);

// Flywheel test
ControllerButton flwBtn( ControllerDigital::L1);

/***************************/
/*******Periphirals*********/
/***************************/
Controller controller; // Controller

// Chassis
std::shared_ptr<ChassisController> drivetrain =
    ChassisControllerBuilder()
        .withMotors({-18, -19, -20}, {11, 12, 13})
        .withDimensions({AbstractMotor::gearset::blue, (60.0 / 36.0)},
                        {{3.25_in, 275.736_mm}, imev5BlueTPR})
        .build();

// Flywheel
Motor armMtr(-16);
Motor flwMtr(-15);
DistanceSensor dist(17);

// Wings
pros::ADIDigitalOut leftWing('A');
pros::ADIDigitalOut rightWing('B');