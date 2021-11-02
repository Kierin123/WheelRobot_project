#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

//#define ONBOARD 

#ifdef ONBOARD
#include <wiringPi.h>
#endif

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

const char l_motor_fifo_name[] = "./l_fifo_command";

pthread_t motor_threads[MOTOR_THREADS_NUM];
int thread_args[MOTOR_THREADS_NUM];


#ifdef ONBOARD

void motor_left_pwm_set(const int pwm)
{
	digitalWrite(EN_MOTORS_PIN, LOW);
	digitalWrite(DIR_MOTOR_L_PIN, LOW);
	pwmWrite(PWM_MOTOR_L_PIN, pwm);
}

void motor_right_pwm_set(const int pwm)
{
	digitalWrite(EN_MOTORS_PIN, LOW);
	digitalWrite(DIR_MOTOR_R_PIN, HIGH);
	pwmWrite(PWM_MOTOR_R_PIN, pwm);
}

void motors_stop()
{
	digitalWrite(EN_MOTORS_PIN, HIGH);
	pwmWrite(PWM_MOTOR_L_PIN, 0);
	pwmWrite(PWM_MOTOR_R_PIN, 0);
}

#endif



void *motor_thread_worker(void *args)
{
	char fifo_arr_read[READ_FIFO_SIZE];

	int fifo_desc = open(l_motor_fifo_name, O_RDWR);
	int id = 1, it = 0;
	int speed = 0;
	int distance = 0;

	while (id)
	{
		read(fifo_desc, fifo_arr_read, READ_FIFO_SIZE);

		
			if (!strncmp(fifo_arr_read, "LS", 2))
			{
				speed = atoi(&fifo_arr_read[2]);
				#ifdef ONBOARD
				motor_left_pwm_set(speed);
				#endif
				printf("MOTOR RIDE! with speed %d\n", speed);
			}
			else if (!strncmp(fifo_arr_read, "LD", 2))
			{
				distance = atoi(&fifo_arr_read[2]);
				printf("MOTOR RIDE! by distance %d mm\n", distance);
			}
			else if (!strncmp(fifo_arr_read, "EXIT", 4))
			{
				id = 0;
			}
			else
			{
				printf("Command unknown: %s", fifo_arr_read);
			}
		
		memcpy(fifo_arr_read,"\0",READ_FIFO_SIZE);
		//for (it = 0; it < READ_FIFO_SIZE; it++)
		//{
		//	fifo_arr_read[it] = 0;
		// }
	}

	close(fifo_desc);
	pthread_exit(NULL);
}

void motors_init()
{
	#ifdef ONBOARD

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

	#endif

	mode_t x_perm = 0777;

	int error_code = mkfifo(l_motor_fifo_name, x_perm);
	if (-1 == error_code)
	{
		printf("Error code: [%d], %s\n", errno, strerror(errno));
		if (errno != EEXIST)
		{
			printf("Errno different than EEXIST!\n");
			exit(EXIT_FAILURE);
		}
	}

	pthread_create(&motor_threads[0], NULL, motor_thread_worker, &thread_args);

	pthread_join(motor_threads[0], NULL);
}



int main(void)
{
	printf("Welcome at WheelRobot application. \nCreated by Marcin Kierinkiewicz 2021\nZachodniopomorski Uniwersytet Szczecinski\n");
	motors_init();
	printf("Program ended.\n");

	return 0;
}
