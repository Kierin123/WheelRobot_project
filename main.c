#include "headers/main.h"

char task_handler(char *command)
{
	char output = 0;
	int _command = command[0];
	int _read_value = atoi(&command[1]);

	switch (_command)
	{
	case STOP:
	{
		if ((_stop_motor(&LeftMotor) == _ACK) && (_stop_motor(&RightMotor) == _ACK))
		{
			output = _ACK; // ACK
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

	case ARC_RIGHT:
	{
		output = _arc(&LeftMotor, &RightMotor, RIGHT, _read_value);
	}
	break;

	case ARC_LEFT:
	{
		output = _arc(&LeftMotor, &RightMotor, LEFT, _read_value);
	}
	break;

	case EXIT:
	{
		if ((_stop_motor(&LeftMotor) == _ACK) && (_stop_motor(&RightMotor) == _ACK))
		{
			output = _ACK; // ACK
		}
		output = EOF; // EOF
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
		output = _ACK;
		break;
	}

	_read_value = 0;

	return output;
}

int main(int argc, char *argv[])
{
	printf("\nWheelRobot App. \nAuthor: Marcin Kierinkiewicz 2021\n");

	// ########################################
	//     Init socket variables
	// ########################################

	int32_t server_socket = 0, new_socket = 0, server_addr_len = 0;
	int32_t *client_socket = (int *)malloc(sizeof(int));
	struct sockaddr_in client;
	uint32_t port = DEFAULT_PORT;
	int32_t read_size = 0;

	uint32_t task_running = 0;

	char read_data[READ_DATA_SIZE] = {0};
	char *single_command = NULL; // = (char *)malloc(sizeof(char) * 5);
	char *client_message = (char *)malloc(sizeof(char) * 12);
	char write_data[WRITE_DATA_SIZE] = {0};

	// Port setup by program start parameters
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

	// ########################################
	//     Motor setup
	// ########################################

	if (!wiringPiSetupGpio())
	{
		printf("Program Init...\n");

		_motor_init(&LeftMotor, PWM_MOTOR_L_PIN, EN_MOTORS_PIN, FAULT_MOTORS_PIN, DIR_MOTOR_L_PIN, &LeftEncoder, ENC_L_OUTPUT_A, ENC_L_OUTPUT_B);

		_motor_init(&RightMotor, PWM_MOTOR_R_PIN, EN_MOTORS_PIN, FAULT_MOTORS_PIN, DIR_MOTOR_R_PIN, &RightEncoder, ENC_R_OUTPUT_A, ENC_R_OUTPUT_B);
	}

	// ########################################
	//     Socket start-up
	// ########################################
	printf("Waiting for incoming connections...\n");
	server_addr_len = sizeof(struct sockaddr_in);

	while ((new_socket = accept(server_socket, (struct sockaddr *)&client, (socklen_t *)&server_addr_len)))
	{
		printf("Client connected.\n");
		task_running = 1;

		char *client_message = "Connected.\n";
		write(new_socket, client_message, strlen(client_message));

		client_socket = (int *)realloc(client_socket, 1);
		*client_socket = new_socket;

		// ########################################
		//     Main loop
		// ########################################

		while (task_running)
		{
			while ((read_size = recv(*client_socket, read_data, CHAR_IN_MESSAGE, 0)) > 0)
			{
				// Parsing commands
				single_command = strtok(read_data, ",");
				while (single_command != NULL)
				{
					write_data[0] = task_handler(single_command);
					while (write_data[0] != _ACK)
					{
						write(*client_socket, write_data, strlen(write_data));
						memset(write_data, '\0', WRITE_DATA_SIZE - 1);
					}
					if (write_data[0] == _EOF)
					{
						break;
					}
					single_command = strtok(NULL, ",");
				}
				memset(read_data, '\0', READ_DATA_SIZE-1);
			}

			task_running = 0u;

			if (read_size == 0u)
			{
				printf("Client disconnected\n");
				fflush(stdout);
			}
			else if (read_size == -1)
			{
				perror("Received failed");
			}
		}
	}

	close(server_socket);
	client_socket = NULL;
	free(client_socket);
	client_message = NULL;
	free(client_message);
	printf("Wheel Robot End.\n");

	return 0;
}
