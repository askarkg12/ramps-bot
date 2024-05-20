 #include <Arduino.h>
#include <stepper_motors.h>
#include <serial_parameters.h>

#include <comms.h>
#include <commands.h>

void setup_serial(){
  Serial.begin(SERIAL_BAUD);
}

bool is_connected = false;



// This should be customisable
void processCommand(){
  if (Serial.available() > 0){
    Command command = receiveCommand();

    if (command == HELLO){
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
        // Insert all commands here. Make sure that arduino and client are synchronised in how commands are processed.
        case SET_MOTOR_SPEEDS:
        {
          setMotorSpeeds();
          break;
        }
        default:
        {
          sendCommand(ERROR);
          break;
        }
      }

    }
    sendCommand(RECEIVED); //Every command should return back with RECEIVED in the end.
  }
}

void setup() {
  // put your setup code here, to run once:
  setup_serial();

  while (!is_connected){
    sendCommand(HELLO);
    waitForBytes(1, 1000);
    processCommand();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
