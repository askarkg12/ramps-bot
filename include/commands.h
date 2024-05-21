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
};

typedef enum Command Command;

void setMotorSpeed(AccelStepper &stepper);
void readSetMotorSpeed(AccelStepper &stepper);
void readRealMotorSpeed(float realSpeed);

#endif