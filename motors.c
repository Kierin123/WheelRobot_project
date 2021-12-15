#include "headers/motors.h"

const char motor_fifo_name[] = "./fifo_command";
pthread_t motor_threads[MOTOR_THREADS_NUM];
int thread_args[MOTOR_THREADS_NUM];

int motor_R_position = 0;
int motor_L_position = 0;

static void motor_left_pwm_set(const int pwm, int dir)
{
    digitalWrite(DIR_MOTOR_L_PIN, !dir);
    pwmWrite(PWM_MOTOR_L_PIN, pwm);
    digitalWrite(EN_MOTORS_PIN, LOW);
}

static void motor_right_pwm_set(const int pwm, int dir)
{
    digitalWrite(DIR_MOTOR_R_PIN, dir);
    pwmWrite(PWM_MOTOR_R_PIN, pwm);
    digitalWrite(EN_MOTORS_PIN, LOW);
}

static void motors_stop()
{
    digitalWrite(EN_MOTORS_PIN, HIGH);
    pwmWrite(PWM_MOTOR_L_PIN, 0);
    pwmWrite(PWM_MOTOR_R_PIN, 0);
}
static void reset_encoders_position()
{
    motor_R_position = 0;
    motor_L_position = 0;
}

static void speed_move(int dir, const int speed)
{
    
    motor_left_pwm_set(speed, dir);
    motor_right_pwm_set(speed, dir);
}

static void distance_move(int dir, const int dist)
{
    reset_encoders_position();
    int actual_posision_mm = 0;
    motor_left_pwm_set(250, dir);
    motor_right_pwm_set(250, dir);
    while (actual_posision_mm <= dist)
    {
        actual_posision_mm = (int)(motor_L_position + motor_R_position) * 61 / 200;
    }

    motors_stop();
}

static void turn(int dir)
{
    if (dir == RIGHT || dir == LEFT)
    {
        reset_encoders_position();
        static int angle;
        motor_left_pwm_set(250, !(dir & 0x01));
        motor_right_pwm_set(250, (dir & 0x02));
        if (dir == RIGHT)
        {
            printf("STOP! Position L: %d Position R: %d angle: %d\n", motor_L_position, motor_R_position, angle);

            while (angle < 40)
            {
                angle = (int)(motor_L_position)*61 / 200;
            }
            printf("STOP! Position L: %d Position R: %d angle: %d\n", motor_L_position, motor_R_position, angle);

            angle = 0;
        }
        else
        {
            printf("STOP! Position L: %d Position R: %d angle: %d\n", motor_L_position, motor_R_position, angle);

            while (angle < 40)
            {
                angle = (int)(motor_R_position)*61 / 200;
            }
            printf("STOP! Position L: %d Position R: %d angle: %d\n", motor_L_position, motor_R_position, angle);
            angle = 0;
        }
    }

    motors_stop();
}

void *motor_command_thread(void *args)
{
    char fifo_arr_read[READ_FIFO_SIZE];

    int fifo_desc = open(motor_fifo_name, O_RDONLY);
    int thread_running = 1;
    // int speed = 0;
    int dist = 0;
    int last_dist = 0;
    // int actual_posision_mm = 0;
    int angle = 0;

    while (thread_running)
    {
        read(fifo_desc, fifo_arr_read, READ_FIFO_SIZE);

        if (!strncmp(fifo_arr_read, "FS", 2))
        {

            speed_move(FORWARD, atoi(&fifo_arr_read[2]));
            // printf("Forward with speed %d\n", speed);
        }
        else if (!strncmp(fifo_arr_read, "BS", 2))
        {
            speed_move(BACKWARD, atoi(&fifo_arr_read[2]));
            // printf("Backward with speed %d\n", speed);
        }
        else if (!strncmp(fifo_arr_read, "ST", 2))
        {
            motors_stop();
            // printf("STOP\n");
        }
        else if (!strncmp(fifo_arr_read, "EXIT", 4))
        {
            motors_stop();
            thread_running = 0;
        }
        else if (!strncmp(fifo_arr_read, "FD", 2))
        {

            distance_move(FORWARD, atoi(&fifo_arr_read[2]));
            // printf("STOP! Position L: %d Position R: %d Last: %d\n", motor_L_position, motor_R_position, last_dist);
            // last_dist = actual_posision_mm;
        }
        else if (!strncmp(fifo_arr_read, "BD", 2))
        {
            distance_move(BACKWARD, atoi(&fifo_arr_read[2]));
        }
        else if (!strncmp(fifo_arr_read, "TL", 2))
        {
            // angle = atoi(&fifo_arr_read[2]);

            turn(LEFT);
            // printf("STOP! turn by 90\n");
            // printf("STOP! Position L: %d Position R: %d Last: %d\n", motor_L_position, motor_R_position, last_dist);

            // angle = 0;
            // last_dist = actual_posision_mm;
        }
        else if (!strncmp(fifo_arr_read, "TR", 2))
        {
            // angle = atoi(&fifo_arr_read[2]);
            turn(RIGHT);
            // printf("STOP! turn by 90\n");
            // printf("STOP! Position L: %d Position R: %d Last: %d\n", motor_L_position, motor_R_position, last_dist);

            // angle = 0;
        }
        else
        {
            // printf("Command unknown: %s", fifo_arr_read);
        }

        strcpy(fifo_arr_read, "\0");
    }

    close(fifo_desc);
    remove(motor_fifo_name);
    pthread_exit(NULL);
}

int encoder_read_Left()
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

int encoder_read_Right()
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

void init_timer()
{
    struct itimerval value;
    // value.it_value.tv_usec = 0; // After the timer is started, the corresponding function will be executed every 2 seconds
    value.it_value.tv_usec = 1000;
    value.it_interval = value.it_value;
    setitimer(ITIMER_REAL, &value, NULL); // Initialize timer and send SIGPROF signal when it expires
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

    mode_t x_perm = S_IRUSR | S_IWUSR | S_IROTH | S_IWOTH | S_IWGRP | S_IRGRP;

    int error_code = mkfifo(motor_fifo_name, x_perm);
    system("chmod 777 fifo_command");
    if (-1 == error_code)
    {
        printf("Error code: [%d], %s\n", errno, strerror(errno));
        if (errno != EEXIST)
        {
            printf("Errno different than EEXIST!\n");
            exit(EXIT_FAILURE);
        }
    }

    signal(SIGALRM, encoder_read);
    init_timer();
    pthread_create(&motor_threads[0], NULL, motor_command_thread, &thread_args);
    pthread_join(motor_threads[0], NULL);
}
