
#include <comms.h>

Command receiveCommand(){
  return (Command) Serial.read();
}

void sendCommand(Command command){
  uint8_t* Command = (uint8_t*) &command;
  Serial.write(Command, sizeof(uint8_t));
}

void send_f32(float num)
{
  FloatUnion floatUnion;
  floatUnion.value = num;
  Serial.write(floatUnion.buffer, 4);
}

void waitForBytes(int numbBytes, unsigned long timeout_ms){
  unsigned long startTime = millis();
  while ((Serial.available() < numbBytes ) && (millis() - startTime < timeout_ms)){}
}

