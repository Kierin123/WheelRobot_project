#ifndef MOTORS_H
#define MOTORS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <sys/time.h>
#include <signal.h>

#include <wiringPi.h>

#define PWM_MOTOR_R_PIN 12
#define PWM_MOTOR_L_PIN 13
#define DIR_MOTOR_R_PIN 24
#define DIR_MOTOR_L_PIN 25
#define EN_MOTORS_PIN 5
#define FAULT_MOTORS_PIN 6
#define ENC_R_OUTPUT_A 19
#define ENC_R_OUTPUT_B 16
#define ENC_L_OUTPUT_A 26
#define ENC_L_OUTPUT_B 20

#define READ_FIFO_SIZE 100
#define MOTOR_THREADS_NUM 2

enum
{
    BACKWARD = 0,
    FORWARD = 1,
    LEFT = 3,
    RIGHT = 4,
};

void motors_init();
void *motor_command_thread(void *args);
// void motors_stop();
// void motor_right_pwm_set(const int pwm, int dir);
// void motor_left_pwm_set(const int pwm, int dir);

void init_timer();
void encoder_read();
int encoder_read_Right();
int encoder_read_Left();



#endif