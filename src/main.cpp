 #include <Arduino.h>
#include <stepper_motors.h>
#include <serial_parameters.h>

#include <comms.h>

void setup_serial(){
  Serial.begin(SERIAL_BAUD);
}

bool is_connected = false;

void setMotorSpeeds(){
  
}

// This should be customisable
void process_command(){
  if (Serial.available() > 0){
    Command command = receiveCommand();

    if (command == HELLO){
      if (!is_connected)
      {
        is_connected = true;
        send_command(HELLO);
      }
      else
      {
        send_command(ALREADY_CONNECTED);
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
          send_command(ERROR);
          break;
        }
      }

    }
    send_command(RECEIVED); //Every command should return back with RECEIVED in the end.
  }
}

void setup() {
  // put your setup code here, to run once:
  setup_serial();

  while (!is_connected){
    send_command(HELLO);
    wait_for_bytes(1, 1000);
    process_command();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
