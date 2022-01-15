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
#define WRITE_FIFO_SIZE 2

#define ACK 0x06

void prepare_file(char file_name[])
{
	mode_t x_perm = S_IXGRP | S_IXOTH | S_IXUSR | S_IRUSR | S_IWUSR | S_IROTH | S_IWOTH | S_IWGRP | S_IRGRP;

	int error_code = mkfifo(file_name, x_perm);

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

	char read_fifo_name[] = "/home/pi/motor/fifo_command";
	char write_fifo_name[] = "/home/pi/motor/fifo_answer";
	int read_desc = 0;
	int write_desc = 0;
	int task_running = 0;
	prepare_file(read_fifo_name);
	prepare_file(write_fifo_name);

	system("chmod 777 /home/pi/motor/fifo_command");
	system("chmod 777 /home/pi/motor/fifo_answer");

	char fifo_arr_read[READ_FIFO_SIZE];
	char fifo_arr_write[WRITE_FIFO_SIZE];
	int read_value = 0;

	read_desc = open(read_fifo_name, O_RDONLY);
	write_desc = open(write_fifo_name, O_WRONLY);

	Tmotor LeftMotor;
	Tencoder LeftEncoder;
	Tmotor RightMotor;
	Tencoder RightEncoder;

	if (!wiringPiSetupGpio())
	{
		printf("Program Init...\n");

		_motor_init(&LeftMotor, PWM_MOTOR_L_PIN, EN_MOTORS_PIN, FAULT_MOTORS_PIN, DIR_MOTOR_L_PIN, &LeftEncoder, ENC_L_OUTPUT_A, ENC_L_OUTPUT_B);

		_motor_init(&RightMotor, PWM_MOTOR_R_PIN, EN_MOTORS_PIN, FAULT_MOTORS_PIN, DIR_MOTOR_R_PIN, &RightEncoder, ENC_R_OUTPUT_A, ENC_R_OUTPUT_B);

		if ((read_desc > 0) && (write_desc > 0))
		{
			printf("Task Start... \n");
			task_running = 1;
		}
	}

	while (task_running)
	{
		read(read_desc, fifo_arr_read, READ_FIFO_SIZE);
		read_value = atoi(&fifo_arr_read[2]);

		if (!strncmp(fifo_arr_read, "FS", 2))
		{
			fifo_arr_write[0] = _speed_move(&LeftMotor, &RightMotor, FORWARD, read_value);
		}
		else if (!strncmp(fifo_arr_read, "BS", 2))
		{
			fifo_arr_write[0] = _speed_move(&LeftMotor, &RightMotor, BACKWARD, read_value);
		}
		else if (!strncmp(fifo_arr_read, "ST", 2))
		{
			if ((_stop_motor(&LeftMotor) == ACK) && (_stop_motor(&RightMotor) == ACK))
			{
				fifo_arr_write[0] = ACK; // ACK
			}
		}
			else if (!strncmp(fifo_arr_read, "FD", 2))
			{
				fifo_arr_write[0] = _distance_move(&LeftMotor, &RightMotor, FORWARD, read_value);
			}
		else if (!strncmp(fifo_arr_read, "BD", 2))
		{
			fifo_arr_write[0] = _distance_move(&LeftMotor, &RightMotor, BACKWARD, read_value);
		}
		else if (!strncmp(fifo_arr_read, "TL", 2))
		{
			fifo_arr_write[0] = _turn(&LeftMotor, &RightMotor, LEFT);
		}
		else if (!strncmp(fifo_arr_read, "TR", 2))
		{
			fifo_arr_write[0] = _turn(&LeftMotor, &RightMotor, RIGHT);
		}
		else if (!strncmp(fifo_arr_read, "ML", 2))
		{
			fifo_arr_write[0] = _set_speed(&LeftMotor, read_value, FORWARD);
		}
		else if (!strncmp(fifo_arr_read, "MR", 2))
		{
			fifo_arr_write[0] = _set_speed(&RightMotor, read_value, FORWARD);
		}
		else if (!strncmp(fifo_arr_read, "EXIT", 4))
		{
			if ((_stop_motor(&LeftMotor) == ACK) && (_stop_motor(&RightMotor) == ACK))
			{
				fifo_arr_write[0] = ACK; // ACK
			}
			task_running = 0;
		}
		else
		{
		}

		if (fifo_arr_write[0] != '\0')
		{
			write(write_desc, fifo_arr_write, WRITE_FIFO_SIZE);
			fifo_arr_write[0] = '\0';
			fifo_arr_write[1] = '\n';
		}

		for (size_t i = 0; i < READ_FIFO_SIZE; i++)
		{
			fifo_arr_read[i] = '\0';
		}
	}

	close(read_desc);
	close(write_desc);

	remove(read_fifo_name);
	remove(write_fifo_name);

	printf("Program stoped.\n");

	return 0;
}
