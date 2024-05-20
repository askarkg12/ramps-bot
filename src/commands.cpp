#include <commands.h>
#include <comms.h>
#include <stepper_motors.h>

void setMotorSpeed(AccelStepper &stepper)
{
    float speed1 = receive_f32();
    stepper.setSpeed(speed1);
}

void readSetMotorSpeed(AccelStepper &stepper) {}
void readRealMotorSpeed(AccelStepper &stepper) {}