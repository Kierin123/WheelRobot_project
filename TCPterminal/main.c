#include <stdio.h>
#include <string.h> //strlen
#include <stdlib.h> //strlen
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr
#include <unistd.h>	   //write
#include <sys/types.h>
#include <fcntl.h>

#define CHAR_IN_MESSAGE 30
#define CHAR_IN_ANSWER 2

void connection_handler(void *socket_desc)
{
	const char motor_fifo_name[] = "/home/pi/motor/fifo_command";
	const char read_fifo_name[] = "/home/pi/motor/fifo_answer";

	// Get the socket descriptor
	int _socket_desc = *(int *)socket_desc;
	int read_size;
	char *message, client_message[CHAR_IN_MESSAGE], client_asnwer[CHAR_IN_ANSWER];

	int fifo_desc = open(motor_fifo_name, O_WRONLY); //O_WRONLY
	int read_desc = open(read_fifo_name, O_RDONLY);	 //O_WRONLY

	// Send some messages to the client
	message = "Connection accepted.\n";
	write(_socket_desc, message, strlen(message));

	// Receive a message from client
	while ((read_size = recv(_socket_desc, client_message, CHAR_IN_MESSAGE, 0)) > 0)
	{
		write(fifo_desc, client_message, strlen(client_message));
		read(read_desc, client_asnwer, CHAR_IN_ANSWER);

		message = "Done\n";
		write(_socket_desc, message, strlen(message));

		for (size_t i = 0; i < CHAR_IN_MESSAGE; i++)
		{
			client_message[i] = '\0';
		}
	}

	if (read_size == 0)
	{
		puts("Client disconnected");
		fflush(stdout);
	}
	else if (read_size == -1)
	{
		perror("recv failed");
	}

	// Free the socket pointer
	free(socket_desc);

	return;
}

int main(int argc, char *argv[])
{
	int socket_desc, new_socket, c, *new_sock;
	struct sockaddr_in server, client;
	char *message;
	int port = 8000;

	if (argc > 1)
	{
		port = atoi(argv[1]);
	}

	// Create socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc == -1)
	{
		printf("Could not create socket");
	}

	// Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(port);

	// Bind
	if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		printf("bind failed");
		return 1;
	}
	puts("bind done");

	// Listen
	listen(socket_desc, 10);

	// Accept and incoming connection
	puts("Waiting for incoming connections...");
	c = sizeof(struct sockaddr_in);
	while (1)
	{
		while ((new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c)))
		{
			puts("Connection accepted");

			// Reply to the client
			message = "Hello Client , I have received your connection.";
			write(new_socket, message, strlen(message));

			new_sock = malloc(1);
			*new_sock = new_socket;

			connection_handler(new_sock);

			puts("Handler assigned");
		}
	}
	if (new_socket < 0)
	{
		perror("accept failed");
		return 1;
	}

	return 0;
}
