#ifndef STEPPER_MOTORS_H
#define STEPPER_MOTORS_H

#include <AccelStepper.h>
// Define motor pins
#define MOTOR_FL_STEP 26  // E0
#define MOTOR_FL_DIR 28
#define MOTOR_FL_EN 24

#define MOTOR_FR_STEP 36  // E1
#define MOTOR_FR_DIR 34
#define MOTOR_FR_EN 30

#define MOTOR_RL_STEP A0  // X
#define MOTOR_RL_DIR A1
#define MOTOR_RL_EN 38

#define MOTOR_RR_STEP A6  // Y
#define MOTOR_RR_DIR A7
#define MOTOR_RR_EN A2

void setupStepperMotor(AccelStepper &stepper, uint8_t enablePin);

#endif