#include "headers/motors.h"



void _motor_init(Tmotor *_motor, int pwm_pin, int enable_pin, int fault_pin, int dir_pin, Tencoder *_enc, \
                 int encoder_pin_a, int encoder_pin_b)
{
    pinMode(pwm_pin, PWM_OUTPUT);
    _motor->pwm_pin = pwm_pin;

    pinMode(dir_pin, OUTPUT);
    _motor->dir_pin = dir_pin;

    pinMode(enable_pin, OUTPUT);
    _motor->enable_pin = enable_pin;

    pinMode(fault_pin, INPUT);
    _motor->fault_pin = fault_pin;

    pinMode(encoder_pin_a, INPUT);

    _enc->a_input_pin = encoder_pin_a;
    pinMode(encoder_pin_b, INPUT);
    _enc->b_input_pin = encoder_pin_b;
    _enc->counter = 0;
    _enc->last_read = 0;

    _motor->encoder = _enc;
}

int _encoder_read(Tencoder *_enc)
{

    unsigned char current_read = 0;
    //static unsigned char last_read;

    current_read = ((digitalRead(_enc->a_input_pin) << 1) + (digitalRead(_enc->b_input_pin))) & 0x03;

    if ((_enc->last_read & 0x03) != current_read)
    {
        _enc->last_read = (_enc->last_read << 2) | current_read;
        // printf("LAST: %d/n", last_read_left);
        if (_enc->last_read == 0x4B || _enc->last_read == 0x87)
        {
            if (_enc->last_read == 0x4B)
            {
                _enc->counter++;
            }
            else
            {
                _enc->counter--;
            }
        }
    }
    return _enc->counter;
}

char _set_speed(Tmotor *_motor, int speed, int dir)
{
    digitalWrite(_motor->dir_pin, dir);
    pwmWrite(_motor->pwm_pin, speed + _motor->motor_speed_faktor);
    digitalWrite(_motor->enable_pin, LOW);
        return ACK;

}

char _stop_motor(Tmotor *_motor)
{
    pwmWrite(_motor->pwm_pin, 0);
    digitalWrite(_motor->enable_pin, HIGH);
        return ACK;

}

char _speed_move(Tmotor *_motor_l, Tmotor *_motor_r, int dir, const int speed)
{
    _set_speed(_motor_l, speed, !dir);
    _set_speed(_motor_r, speed, dir);
        return ACK;

}

char _distance_move(Tmotor *_motor_l, Tmotor *_motor_r, int dir, const int dist)
{
    _encoder_read(_motor_l->encoder);
    _encoder_read(_motor_r->encoder);

    int last_position = (int)(_motor_l->encoder->counter + _motor_r->encoder->counter) * DISTANCE_ENC_FACTOR;
    int actual_posision_mm = (int)(_motor_l->encoder->counter + _motor_r->encoder->counter) * DISTANCE_ENC_FACTOR;
    _speed_move(_motor_l, _motor_r, dir, 250);

    if (dir == FORWARD)
    {
        while (actual_posision_mm <= (last_position + dist))
        {
            _encoder_read(_motor_r->encoder);
            _encoder_read(_motor_l->encoder);


            actual_posision_mm = (int)(_motor_l->encoder->counter + _motor_r->encoder->counter) * DISTANCE_ENC_FACTOR;
        }
    }
    if (dir == BACKWARD)
    {
        while (actual_posision_mm >= (last_position - dist))
        {
            _encoder_read(_motor_r->encoder);
            _encoder_read(_motor_l->encoder);

            actual_posision_mm = (int)(_motor_l->encoder->counter + _motor_r->encoder->counter) * DISTANCE_ENC_FACTOR;
        }
    }

    last_position = actual_posision_mm;
    _stop_motor(_motor_r);
    _stop_motor(_motor_l);
        return ACK;

}

char _turn(Tmotor *_motor_l, Tmotor *_motor_r, int dir)
{
    if (dir == RIGHT || dir == LEFT)
    {
        _encoder_read(_motor_l->encoder);
        _encoder_read(_motor_r->encoder);
        int last_R_position = _motor_r->encoder->counter;
        int last_L_position = _motor_l->encoder->counter;

        // int angle = 0;
        _set_speed(_motor_l, 250, (dir & 0x01));
        _set_speed(_motor_r, 250, (dir & 0x02));

        if (dir == LEFT)
        {
            while (_motor_r->encoder->counter < (last_R_position + TURN_90_DEGREE))
            {
                _encoder_read(_motor_r->encoder);
            }
        }
        else
        {
            while (_motor_l->encoder->counter < (last_L_position + TURN_90_DEGREE))
            {
                _encoder_read(_motor_l->encoder);
            }
        }
    }


    _stop_motor(_motor_r);
    _stop_motor(_motor_l);
    return ACK;
}

char _set_motor_faktor(Tmotor *_motor, int value)
{
    _motor->motor_speed_faktor = value;
    return ACK;
}


