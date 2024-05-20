#ifndef PARAMETERS_H
#define PARAMETERS_H

#define SERIAL_BAUD 115200  // Baudrate

enum Command {
    HELLO = 0,
    RECEIVED = 1,
    ALREADY_CONNECTED = 2,
    ERROR = 3,
    SET_MOTOR_SPEEDS = 4,
};

typedef enum Command Command;

#endif
