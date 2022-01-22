#include "headers/main.h"

int main(int argc, char *argv[])
{
	printf("\nWelcome at WheelRobot App. \nCreated by Marcin Kierinkiewicz 2021\n");

	int server_socket, new_socket, server_addr_len;
	int *client_socket = (int *)malloc(sizeof(int));
	struct sockaddr_in client;
	int read_size = 0;
	char *client_message = (char *)malloc(6);
	int port = DEFAULT_PORT;
	int task_running = 0;

	if (argc > 1)
	{
		port = atoi(argv[1]);
	}

	server_socket = socket_init(port);
	if (server_socket < 0)
	{
		perror("Socket create error");
		return -1;
	}

	char read_data[READ_FIFO_SIZE];
	char *single_command; // = (char *)malloc(sizeof(char) * 5);

	char write_data[WRITE_FIFO_SIZE] = {0};

	// int read_value = 0;

	if (!wiringPiSetupGpio())
	{
		printf("Program Init...\n");

		_motor_init(&LeftMotor, PWM_MOTOR_L_PIN, EN_MOTORS_PIN, FAULT_MOTORS_PIN, DIR_MOTOR_L_PIN, &LeftEncoder, ENC_L_OUTPUT_A, ENC_L_OUTPUT_B);

		_motor_init(&RightMotor, PWM_MOTOR_R_PIN, EN_MOTORS_PIN, FAULT_MOTORS_PIN, DIR_MOTOR_R_PIN, &RightEncoder, ENC_R_OUTPUT_A, ENC_R_OUTPUT_B);
	}

	printf("Waiting for incoming connections...\n");
	server_addr_len = sizeof(struct sockaddr_in);

	while ((new_socket = accept(server_socket, (struct sockaddr *)&client, (socklen_t *)&server_addr_len)))
	{
		printf("Client connected.\n");
		task_running = 1;

		client_message = "Connected to WheelRobot!\n";
		write(new_socket, client_message, strlen(client_message));

		client_socket = (int *)realloc(client_socket, 1);
		*client_socket = new_socket;

		while (task_running)
		{
			while ((read_size = recv(*client_socket, read_data, CHAR_IN_MESSAGE, 0)) > 0)
			{

				// printf("Read size: %d; Data: %s", read_size, read_data);

				single_command = strtok(read_data, ",");
				while (single_command != NULL)
				{

					write_data[0] = task_handler(single_command);
					while (write_data[0] != ACK)
					{
						write(*client_socket, write_data, strlen(write_data));
						// memset(write_data, 0, strlen(write_data));
						write_data[0] = 0;
					}
					if (write_data[0] == 0x04)
					{
						break;
					}

					// memset(single_command, 0, 5);

					single_command = strtok(NULL, ",");
				}

				// memset(read_data, 0, strlen(read_data));

				for (size_t i = 0; i < READ_FIFO_SIZE; i++)
				{
					read_data[i] = '\0';
				}
			}

			task_running = 0;

			if (read_size == 0)
			{
				printf("Client disconnected\n");
				fflush(stdout);
			}
			else if (read_size == -1)
			{
				perror("recv failed");
			}
		}
	}

	close(server_socket);
	free(client_socket);
	free(client_message);
	printf("Wheel Robot End.\n");

	return 0;
}

char task_handler(char *command)
{
	char output = 0;
	int _command = command[0];
	int _read_value = atoi(&command[1]);

	switch (_command)
	{

	case STOP:
	{
		if ((_stop_motor(&LeftMotor) == ACK) && (_stop_motor(&RightMotor) == ACK))
		{
			output = ACK; // ACK
		}
	}
	break;

	case TURN_LEFT:
	{
		output = _turn(&LeftMotor, &RightMotor, LEFT);
	}
	break;

	case TURN_RIGHT:
	{
		output = _turn(&LeftMotor, &RightMotor, RIGHT);
	}
	break;

	case FORWARD_DISTANCE:
	{
		output = _distance_move(&LeftMotor, &RightMotor, FORWARD, _read_value);
	}
	break;

	case BACKWARD_DISTANCE:
	{
		output = _distance_move(&LeftMotor, &RightMotor, BACKWARD, _read_value);
	}
	break;

	case FORWARD_SPEED:
	{
		output = _speed_move(&LeftMotor, &RightMotor, FORWARD, _read_value);
	}
	break;

	case BACKWARD_SPEED:
	{
		output = _speed_move(&LeftMotor, &RightMotor, BACKWARD, _read_value);
	}
	break;

	case MOTOR_LEFT:
	{
		output = _set_speed(&LeftMotor, _read_value, FORWARD);
	}
	break;

	case MOTOR_RIGHT:
	{
		output = _set_speed(&RightMotor, _read_value, FORWARD);
	}
	break;

	case EXIT:
	{
		if ((_stop_motor(&LeftMotor) == ACK) && (_stop_motor(&RightMotor) == ACK))
		{
			output = ACK; // ACK
		}
		output = 0x04; // EOF
	}
	break;

	case CHANGE_FAKTOR_L:
	{
		output = _set_motor_faktor(&LeftMotor, _read_value);
	}
	break;
	case CHANGE_FAKTOR_R:
	{
		output = _set_motor_faktor(&RightMotor, _read_value);
	}
	break;

	default:
		output = ACK;
		break;
	}

	_read_value = 0;

	return output;
}