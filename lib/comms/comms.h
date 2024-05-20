
#include <Arduino.h>
#include <serial_parameters.h>

union FloatUnion{
    byte buffer[4];
    float value;
  };

Command receiveCommand(Command command);
void sendCommand(Command command);
void send_f32(float num);
void waitForBytes(int numbBytes, unsigned long timeout_ms);
