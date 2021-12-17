#ifndef ENCODER_H
#define ENCODER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include <wiringPi.h>



#define ENC_R_OUTPUT_A 19
#define ENC_R_OUTPUT_B 16
#define ENC_L_OUTPUT_A 26
#define ENC_L_OUTPUT_B 20

#define READ_FIFO_SIZE 100
#define MOTOR_THREADS_NUM 2


void encoder_init();
void encoder_read();

#endif