#include "headers/motors.h"

int motor_R_position = 0;
int motor_L_position = 0;

// const char motor_fifo_name[] = "./fifo_command";
// pthread_t motor_threads[MOTOR_THREADS_NUM];
// int thread_args[MOTOR_THREADS_NUM];



static void motor_left_pwm_set(const int pwm, int dir)
{
    digitalWrite(DIR_MOTOR_L_PIN, !dir);
    pwmWrite(PWM_MOTOR_L_PIN, pwm + LEFT_MOTOR_FACTOR);
    digitalWrite(EN_MOTORS_PIN, LOW);
}

static void motor_right_pwm_set(const int pwm, int dir)
{
    digitalWrite(DIR_MOTOR_R_PIN, dir);
    pwmWrite(PWM_MOTOR_R_PIN, pwm + RIGHT_MOTOR_FACTOR);
    digitalWrite(EN_MOTORS_PIN, LOW);
}

 void motors_stop()
{
    digitalWrite(EN_MOTORS_PIN, HIGH);
    pwmWrite(PWM_MOTOR_L_PIN, 0);
    pwmWrite(PWM_MOTOR_R_PIN, 0);
}


 void speed_move(int dir, const int speed)
{

    motor_left_pwm_set(speed, dir);
    motor_right_pwm_set(speed, dir);
}

 void distance_move(int dir, const int dist)
{
    encoder_read();
    static int last_position = 0;
    int actual_posision_mm = (int)(motor_L_position + motor_R_position) * 61 / 200;
    motor_left_pwm_set(250, dir);
    motor_right_pwm_set(250, dir);
    if (dir == FORWARD)
    {
        while (actual_posision_mm <= (dist + last_position))
        {
            encoder_read();
            actual_posision_mm = (int)(motor_L_position + motor_R_position) * 61 / 200;
        }
    }
    if (dir == BACKWARD)
    {
        while (actual_posision_mm >= (last_position - dist))
        {
            encoder_read();
            actual_posision_mm = (int)(motor_L_position + motor_R_position) * 61 / 200;
        }
    }

    last_position = actual_posision_mm;
    motors_stop();
}

 void turn(int dir)
{
    if (dir == RIGHT || dir == LEFT)
    {
        encoder_read();
        int last_R_position = motor_R_position;
        int last_L_position = motor_L_position;

        int angle = 0;
        motor_left_pwm_set(250, !(dir & 0x01));
        motor_right_pwm_set(250, (dir & 0x02));
        if (dir == RIGHT)
        {

            while (motor_L_position < (last_L_position + TURN_90_DEGREE))
            {
                encoder_read();
            }
        }
        else
        {

            while (motor_R_position < (last_R_position + TURN_90_DEGREE))
            {
                encoder_read();
            }
        }
    }

    motors_stop();
}



static int encoder_read_Left()
{
    static int counter = 0;
    unsigned char current_read_left = 0;
    // unsigned char current_read_right = 0;
    static unsigned char last_read_left;
    // static unsigned char last_read_right;

    current_read_left = ((digitalRead(ENC_L_OUTPUT_A) << 1) + (digitalRead(ENC_L_OUTPUT_B))) & 0x03;

    if ((last_read_left & 0x03) != current_read_left)
    {
        last_read_left = (last_read_left << 2) | current_read_left;
        // printf("LAST: %d/n", last_read_left);
        if (last_read_left == 0x4B || last_read_left == 0x87)
        {

            if (last_read_left == 0x4B)
            {
                counter++;
            }
            else
            {
                counter--;
            }
        }
    }
    return counter;
}

static int encoder_read_Right()
{
    static int counter = 0;
    // unsigned char current_read_left = 0;
    unsigned char current_read_right = 0;
    // static unsigned char last_read_left;
    static unsigned char last_read_right;

    current_read_right = ((digitalRead(ENC_R_OUTPUT_A) << 1) + (digitalRead(ENC_R_OUTPUT_B))) & 0x03;

    if ((last_read_right & 0x03) != current_read_right)
    {
        last_read_right = (last_read_right << 2) | current_read_right;
        // printf("LAST: %d/n", last_read_left);
        if (last_read_right == 0x4B || last_read_right == 0x87)
        {

            if (last_read_right == 0x4B)
            {
                counter++;
            }
            else
            {
                counter--;
            }
        }
    }

    return counter;
}

void encoder_read()
{
    motor_L_position = encoder_read_Left();
    motor_R_position = encoder_read_Right();
}



void motors_init()
{

    wiringPiSetupGpio();

    pinMode(PWM_MOTOR_R_PIN, PWM_OUTPUT);
    pinMode(PWM_MOTOR_L_PIN, PWM_OUTPUT);

    pinMode(DIR_MOTOR_R_PIN, OUTPUT);
    pinMode(DIR_MOTOR_L_PIN, OUTPUT);

    pinMode(EN_MOTORS_PIN, OUTPUT);
    pinMode(FAULT_MOTORS_PIN, INPUT);

    pinMode(ENC_R_OUTPUT_A, INPUT);
    pinMode(ENC_L_OUTPUT_A, INPUT);
    pinMode(ENC_R_OUTPUT_B, INPUT);
    pinMode(ENC_L_OUTPUT_B, INPUT);

    
   
    //pthread_create(&motor_threads[0], NULL, motor_command_thread, &thread_args);
   // pthread_join(motor_threads[0], NULL);
}
