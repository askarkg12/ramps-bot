#include <stepper_motors.h>

void setupStepperMotor(AccelStepper &stepper, uint8_t enablePin)
{
    stepper.setEnablePin(enablePin);
    stepper.setPinsInverted(false, false, true);
    stepper.enableOutputs();
    stepper.setMaxSpeed(5000);
    stepper.setSpeed(0);
}
MotorBundle::MotorBundle(AccelStepper &stepper) : stepper(stepper), realSpeed(0.0), lastStepTime(0), currentTime(0), timeInterval(0) {}

void MotorBundle::runSpeedTracked()
{
    if (stepper.runSpeed())
    {
        currentTime = micros();
        timeInterval = currentTime - lastStepTime;

        if (timeInterval > 0)
        {
            realSpeed = 1000000.0 / timeInterval;
        }

        lastStepTime = currentTime;
    }
}
