#include "assignment.h"

Controller controller; // Controller

// Chassis
std::shared_ptr<ChassisController> drivetrain =
    ChassisControllerBuilder()
        .withMotors({-1, -2, -3}, {6, 7, 10})
        .withDimensions({AbstractMotor::gearset::blue, (60.0 / 36.0)},
                        {{3.25_in, 10.1993_in}, imev5BlueTPR})
        .build();
