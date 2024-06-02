#include <Arduino.h>
#include <comms.h>
#include <stepper_motors.h>
#include <serial_parameters.h>
#include <commands.h>

void setup_serial()
{
  Serial.begin(SERIAL_BAUD);
}

bool is_connected = false;

AccelStepper stepperFL(AccelStepper::DRIVER, MOTOR_FL_STEP, MOTOR_FL_DIR);
AccelStepper stepperFR(AccelStepper::DRIVER, MOTOR_FR_STEP, MOTOR_FR_DIR);
AccelStepper stepperRL(AccelStepper::DRIVER, MOTOR_RL_STEP, MOTOR_RL_DIR);
AccelStepper stepperRR(AccelStepper::DRIVER, MOTOR_RR_STEP, MOTOR_RR_DIR);

AccelStepper* steppers[] = { &stepperFL, &stepperFR, &stepperRL, &stepperRR };

MotorBundle motorBundle_FL(stepperFL);
MotorBundle motorBundle_FR(stepperFR);
MotorBundle motorBundle_RL(stepperRL);
MotorBundle motorBundle_RR(stepperRR);

MotorBundle* motorBundles[] = { &motorBundle_FL, &motorBundle_FR, &motorBundle_RL, &motorBundle_RR };

float realSpeed_FL, realSpeed_FR, realSpeed_RL, realSpeed_RR;

int8_t index = 200;
// This should be customisable
void processCommand()
{
  if (Serial.available() > 0)
  {
    Command command = receiveCommand();

    if (command == HELLO)
    {
      if (!is_connected)
      {
        is_connected = true;
        sendCommand(HELLO);
      }
      else
      {
        sendCommand(ALREADY_CONNECTED);
      }
    }
    else
    {
      switch (command)
      {
        // Insert all commands here. Make sure that arduino and client are synchronized in how commands are processed.
        case SET_MOTOR_SPEEDS: {
          setMotorSpeed(stepperFL);
          setMotorSpeed(stepperFR);
          setMotorSpeed(stepperRL);
          setMotorSpeed(stepperRR);
          break;
        }
        case READ_REAL_MOTOR_SPEEDS: {
          readRealMotorSpeeds(motorBundle_FL.realSpeed);
          readRealMotorSpeeds(motorBundle_FR.realSpeed);
          readRealMotorSpeeds(motorBundle_RL.realSpeed);
          readRealMotorSpeeds(motorBundle_RR.realSpeed);
          break;
        }
        case READ_SET_MOTOR_SPEEDS: {
          readSetMotorSpeeds(stepperFL);
          readSetMotorSpeeds(stepperFR);
          readSetMotorSpeeds(stepperRL);
          readSetMotorSpeeds(stepperRR);
          break;
        }
        case ENABLE_MOTOR: {
          index = receive_i8();
          steppers[index]->enableOutputs();
          break;
        }
        case DISABLE_MOTOR: {
          index = receive_i8();
          steppers[index]->disableOutputs();
          break;
        }
        case SET__MOTOR_SPEED: {
          index = receive_i8();
          steppers[index]->setSpeed(receive_f32());
          break;
        }
        case READ_SET_MOTOR_SPEED: {
          index = receive_i8();
          send_f32(steppers[index]->speed());
          break;
        }
        case READ_REAL_MOTOR_SPEED: {
          index = receive_i8();
          send_f32(motorBundles[index]->realSpeed);
          break;
        }
        default: {
          sendCommand(ERROR);
          break;
        }
      }
    }
    sendCommand(RECEIVED);  // Every command should return back with RECEIVED in the end.
  }
}

void setup()
{
  // put your setup code here, to run once:
  setup_serial();

  setupStepperMotor(stepperFL, MOTOR_FL_EN);
  setupStepperMotor(stepperFR, MOTOR_FR_EN);
  setupStepperMotor(stepperRL, MOTOR_RL_EN);
  setupStepperMotor(stepperRR, MOTOR_RR_EN);

  while (!is_connected)
  {
    sendCommand(HELLO);
    waitForBytes(1, 1000);
    processCommand();
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
  processCommand();

  motorBundle_FL.runSpeedTracked();
  motorBundle_FR.runSpeedTracked();
  motorBundle_RL.runSpeedTracked();
  motorBundle_RR.runSpeedTracked();
}
