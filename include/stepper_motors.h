#ifndef STEPPER_MOTORS_H
#define STEPPER_MOTORS_H

#include <AccelStepper.h>
// Define motor pins
#define MOTOR1_STEP 26  // E0
#define MOTOR1_DIR 28
#define MOTOR1_EN 24

#define MOTOR2_STEP 36  // E1
#define MOTOR2_DIR 34
#define MOTOR2_EN 30

#define MOTOR3_STEP A0  // X
#define MOTOR3_DIR A1
#define MOTOR3_EN 38

#define MOTOR4_STEP A6  // Y
#define MOTOR4_DIR A7
#define MOTOR4_EN A2

AccelStepper stepperFL(AccelStepper::DRIVER, MOTOR1_STEP, MOTOR1_DIR);
AccelStepper stepperFR(AccelStepper::DRIVER, MOTOR2_STEP, MOTOR2_DIR);
AccelStepper stepperRL(AccelStepper::DRIVER, MOTOR3_STEP, MOTOR3_DIR);
AccelStepper stepperRR(AccelStepper::DRIVER, MOTOR4_STEP, MOTOR4_DIR);

#endif