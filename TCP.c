#include "headers/TCP.h"

int socket_init(int _port)
{
    int socket_desc;
    struct sockaddr_in server;
    int port = _port;

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1)
    {
        perror("Could not create socket");
        return -1;
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);

    // Bind
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("bind failed");
        return -1;
    }
    printf("bind done\n");

    listen(socket_desc, 10);

    return socket_desc;
}

