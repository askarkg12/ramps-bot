#include <commands.h>
#include <comms.h>
#include <stepper_motors.h>

void setMotorSpeed(AccelStepper &stepper)
{
    stepper.setSpeed(receive_f32());
}

void readSetMotorSpeeds(AccelStepper &stepper)
{
    send_f32(stepper.speed());
}
void readRealMotorSpeeds(float realSpeed)
{
    send_f32(realSpeed);
}

void enableMotor(AccelStepper &stepper)
{
    
}