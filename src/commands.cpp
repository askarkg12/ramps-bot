#include <commands.h>
#include <comms.h>
#include <stepper_motors.h>

void setMotorSpeed(AccelStepper &stepper)
{
    stepper.setSpeed(receive_f32());
}

void readSetMotorSpeed(AccelStepper &stepper)
{
    send_f32(stepper.speed());
}
void readRealMotorSpeed(float realSpeed)
{
    send_f32(realSpeed);
}