#ifndef MOTORS_H
#define MOTORS_H

#include <stdio.h>
#include <wiringPi.h>
#include <math.h>

// #########################################
//          "Pin configuration"
// set pins according to electronic diagram
// #########################################

#define PWM_MOTOR_R_PIN     12
#define PWM_MOTOR_L_PIN     13
#define DIR_MOTOR_R_PIN     24
#define DIR_MOTOR_L_PIN     25
#define EN_MOTORS_PIN       5
#define FAULT_MOTORS_PIN    6
#define ENC_R_OUTPUT_A      19
#define ENC_R_OUTPUT_B      16
#define ENC_L_OUTPUT_A      26
#define ENC_L_OUTPUT_B      20

// Magic numbers - experimental developed 

#define TURN_90_DEGREE      165
#define DISTANCE_ENC_FACTOR 65 / 200 

#define ACK 0x06

enum
{
    BACKWARD =      0,
    FORWARD =       1,
    LEFT =          3,
    RIGHT =         4,
};

typedef struct
{
    int             a_input_pin;
    int             b_input_pin;

    int             counter;
    unsigned char   last_read;

} Tencoder;

typedef struct
{
    int             pwm_pin;
    int             enable_pin;
    int             fault_pin;
    int             dir_pin;

    int             speed;
    int             state;

    int             motor_speed_faktor;

    Tencoder        *encoder;

} Tmotor;

// static int motor_R_position = 0;
// static int motor_L_position = 0;

// int RIGHT_MOTOR_FACTOR = 4;
// int LEFT_MOTOR_FACTOR = 0;


void _motor_init(Tmotor *_motor, int pwm_pin, int enable_pin, int fault_pin, int dir_pin, Tencoder *_enc, int encoder_pin_a, int encoder_pin_b);
int _encoder_read(Tencoder *_enc);
char _set_speed(Tmotor *_motor, int speed, int dir);
char _stop_motor(Tmotor *_motor);
char _speed_move(Tmotor *_motor_l, Tmotor *_motor_r, int dir, const int speed);
char _distance_move(Tmotor *_motor_l, Tmotor *_motor_r, int dir, const int dist);
char _turn(Tmotor *_motor_l, Tmotor *_motor_r, int dir);
char _set_motor_faktor(Tmotor *_motor, int value);

#endif
