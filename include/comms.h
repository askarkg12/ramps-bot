#ifndef COMMS_H
#define COMMS_H

#include <Arduino.h>
#include <commands.h>

union FloatUnion{
    byte buffer[4];
    float value;
  };

Command receiveCommand();
float receive_f32();
int8_t receive_i8();

void sendCommand(Command command);
void send_f32(float num);

void waitForBytes(int numbBytes, unsigned long timeout_ms);

#endif