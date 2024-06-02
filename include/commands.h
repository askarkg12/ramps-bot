#ifndef COMMANDS_H
#define COMMANDS_H

#include <AccelStepper.h>

enum Command
{
    HELLO = 0,
    RECEIVED = 1,
    ALREADY_CONNECTED = 2,
    ERROR = 3,
    SET_MOTOR_SPEEDS = 4,
    READ_SET_MOTOR_SPEEDS = 5,
    READ_REAL_MOTOR_SPEEDS = 6,
    ENABLE_MOTOR = 7,
    DISABLE_MOTOR = 8,
    SET__MOTOR_SPEED = 9,
    READ_SET_MOTOR_SPEED = 10,
    READ_REAL_MOTOR_SPEED = 11,
};

typedef enum Command Command;

void setMotorSpeed(AccelStepper &stepper);
void readSetMotorSpeeds(AccelStepper &stepper);
void readRealMotorSpeeds(float realSpeed);

#endif