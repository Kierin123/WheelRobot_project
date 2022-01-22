#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

#include "motors.h"
#include "TCP.h"

#define READ_FIFO_SIZE 100
#define WRITE_FIFO_SIZE 2
#define ACK 0x06

#define DEFAULT_PORT 5050

Tmotor LeftMotor;
Tencoder LeftEncoder;
Tmotor RightMotor;
Tencoder RightEncoder;

char task_handler(char *command);


enum 
{
    FORWARD_SPEED = 'X',
    BACKWARD_SPEED = 'Z',
    STOP = 'S',
    FORWARD_DISTANCE = 'F',
    BACKWARD_DISTANCE = 'B', 
    TURN_LEFT = 'L',
    TURN_RIGHT = 'R',
    MOTOR_LEFT = 'M',
    MOTOR_RIGHT = 'N',
    EXIT = 'E',
    CHANGE_FAKTOR_L = 'H',
    CHANGE_FAKTOR_R = 'G',
};