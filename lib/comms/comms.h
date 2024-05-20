
#include <Arduino.h>
#include <serial_parameters.h>

union FloatUnion{
    byte buffer[4];
    float value;
  };

void send_command(Command command);
void send_f32(float num);
void wait_for_bytes(int numbBytes, unsigned long timeout_ms);