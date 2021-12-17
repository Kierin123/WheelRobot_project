#include <stdio.h>
#include "headers/motors.h"
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	printf("Welcome at WheelRobot App. \nCreated by Marcin Kierinkiewicz 2021\n");

	const char motor_fifo_name[] = "/home/pi/motor/fifo_command";

	mode_t x_perm = S_IRUSR | S_IWUSR | S_IROTH | S_IWOTH | S_IWGRP | S_IRGRP;

	int error_code = mkfifo(motor_fifo_name, x_perm);
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

	motors_init();

	char fifo_arr_read[READ_FIFO_SIZE];

	int fifo_desc = open(motor_fifo_name, O_RDONLY);
	int task_running = 1;

	

		while (task_running)
		{
			read(fifo_desc, fifo_arr_read, READ_FIFO_SIZE);

			if (!strncmp(fifo_arr_read, "FS", 2))
			{

				speed_move(FORWARD, atoi(&fifo_arr_read[2]));
			}
			else if (!strncmp(fifo_arr_read, "BS", 2))
			{
				speed_move(BACKWARD, atoi(&fifo_arr_read[2]));
			}
			else if (!strncmp(fifo_arr_read, "ST", 2))
			{
				motors_stop();
			}
			else if (!strncmp(fifo_arr_read, "EXIT", 4))
			{
				motors_stop();
				task_running = 0;
			}
			else if (!strncmp(fifo_arr_read, "FD", 2))
			{

				distance_move(FORWARD, atoi(&fifo_arr_read[2]));
			}
			else if (!strncmp(fifo_arr_read, "BD", 2))
			{
				distance_move(BACKWARD, atoi(&fifo_arr_read[2]));
			}
			else if (!strncmp(fifo_arr_read, "TL", 2))
			{

				turn(LEFT);
			}
			else if (!strncmp(fifo_arr_read, "TR", 2))
			{
				turn(RIGHT);
			}
			else
			{
				
			}
			fflush(stdin);
			strcpy(fifo_arr_read, "\0");
		}
	

	close(fifo_desc);
	remove(motor_fifo_name);
	printf("Program stoped.\n");

	return 0;
}
