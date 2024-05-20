#include <commands.h>

void setMotorSpeeds(){
    float speed1 = receive_f32();
    stepperFL.setSpeed(speed1);
}