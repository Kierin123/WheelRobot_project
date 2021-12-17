#include "headers/encoder.h"


int motor_R_position = 0;
int motor_L_position = 0;


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

