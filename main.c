#include <stdio.h>
#include "headers/motors.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

#define READ_FIFO_SIZE 30

void prepare_file(char file_name[])
{
	mode_t x_perm = S_IRUSR | S_IWUSR | S_IROTH | S_IWOTH | S_IWGRP | S_IRGRP;

	int error_code = mkfifo(file_name, x_perm);
	system("chmod 766 fifo_command");
	if (-1 == error_code)
	{
		printf("Error code: [%d], %s\n", errno, strerror(errno));
		if (errno != EEXIST)
		{
			printf("Errno different than EEXIST!\n");
			exit(EXIT_FAILURE);
		}
	}
}

int main(void)
{
	printf("\nWelcome at WheelRobot App. \nCreated by Marcin Kierinkiewicz 2021\n");

	char motor_fifo_name[] = "/home/pi/motor_test/fifo_command";
	int fifo_desc = 0;
	int task_running = 0;
	prepare_file(motor_fifo_name);

	char fifo_arr_read[READ_FIFO_SIZE];
	int read_value = 0;
	fifo_desc = open(motor_fifo_name, O_RDONLY);

	Tmotor LeftMotor;
	Tencoder LeftEncoder;
	Tmotor RightMotor;
	Tencoder RightEncoder;

	if (!wiringPiSetupGpio())
	{
		printf("Program Init...\n");

		_motor_init(&LeftMotor, PWM_MOTOR_L_PIN, EN_MOTORS_PIN, FAULT_MOTORS_PIN, DIR_MOTOR_L_PIN,
					&LeftEncoder, ENC_L_OUTPUT_A, ENC_L_OUTPUT_B);

		_motor_init(&RightMotor, PWM_MOTOR_R_PIN, EN_MOTORS_PIN, FAULT_MOTORS_PIN, DIR_MOTOR_R_PIN,
					&RightEncoder, ENC_R_OUTPUT_A, ENC_R_OUTPUT_B);

		if (fifo_desc > 0)
		{
			printf("Task Start... \n");
			task_running = 1;
		}
	}

	while (task_running)
	{
		read(fifo_desc, fifo_arr_read, READ_FIFO_SIZE);
		read_value = atoi(&fifo_arr_read[2]);

		if (!strncmp(fifo_arr_read, "FS", 2))
		{
			_speed_move(&LeftMotor, &RightMotor, FORWARD, read_value);
		}
		else if (!strncmp(fifo_arr_read, "BS", 2))
		{
			_speed_move(&LeftMotor, &RightMotor, BACKWARD, read_value);
		}
		else if (!strncmp(fifo_arr_read, "ST", 2))
		{
			_stop_motor(&LeftMotor);
			_stop_motor(&RightMotor);
		}
		else if (!strncmp(fifo_arr_read, "EXIT", 4))
		{
			_stop_motor(&LeftMotor);
			_stop_motor(&RightMotor);
			task_running = 0;
		}
		else if (!strncmp(fifo_arr_read, "FD", 2))
		{
			_distance_move(&LeftMotor, &RightMotor, FORWARD, read_value);
		}
		else if (!strncmp(fifo_arr_read, "BD", 2))
		{
			_distance_move(&LeftMotor, &RightMotor, BACKWARD, read_value);
		}
		else if (!strncmp(fifo_arr_read, "TL", 2))
		{
			_turn(&LeftMotor, &RightMotor, LEFT);
		}
		else if (!strncmp(fifo_arr_read, "TR", 2))
		{
			_turn(&LeftMotor, &RightMotor, RIGHT);
		}
		else if (!strncmp(fifo_arr_read, "ML", 2))
		{
			_set_speed(&LeftMotor, read_value, FORWARD);
		}
		else if (!strncmp(fifo_arr_read, "MR", 2))
		{
			_set_speed(&RightMotor, read_value, FORWARD);
		}
		else
		{
		}
		//fflush(stdin);
		for (size_t i = 0; i < READ_FIFO_SIZE; i++)
		{
			fifo_arr_read[i] = '\0';
		}
	}

	close(fifo_desc);
	remove(motor_fifo_name);
	printf("Program stoped.\n");

	return 0;
}
