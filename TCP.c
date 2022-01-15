#include <headers/TCP.h>


void socket_init(int _port)
{
    int socket_desc, new_socket, c, *new_sock;
	struct sockaddr_in server, client;
	char *message;
	int port = _port;


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
	printf("bind done\n");

}

