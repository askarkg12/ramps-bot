#include <Arduino.h>
#include <stepper_motors.h>
#include <serial_parameters.h>

#include <comms.h>

void setup_serial(){
  Serial.begin(SERIAL_BAUD);
}

bool is_connected = false;


void setup() {
  // put your setup code here, to run once:
  setup_serial();

  while (!is_connected){
    send_command(HELLO);
    wait_for_bytes(1, 1000);

  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
