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

#define READ_DATA_SIZE 300
#define WRITE_DATA_SIZE 2
#define _ACK 0x06
#define _EOF 0x04

#define DEFAULT_PORT 5050


Tmotor      LeftMotor;
Tencoder    LeftEncoder;
Tmotor      RightMotor;
Tencoder    RightEncoder;

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
    CHANGE_FAKTOR_L = 'G',
    CHANGE_FAKTOR_R = 'H',
    ARC_RIGHT = 'W',
    ARC_LEFT = 'Q',
};