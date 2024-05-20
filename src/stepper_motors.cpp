#include <stepper_motors.h>

void setupStepperMotor(AccelStepper &stepper, uint8_t enablePin){
    stepper.setEnablePin(enablePin);
    stepper.setPinsInverted(false, false, true);
    stepper.enableOutputs();
    stepper.setMaxSpeed(5000);
    stepper.setSpeed(0);
}
