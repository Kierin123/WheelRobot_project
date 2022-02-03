#include "headers/TCP.h"

int32_t socket_init(uint32_t _port)
{
    int32_t socket_desc;
    struct sockaddr_in server;
    uint32_t port = _port;

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
    printf("Bind done...\n");

    listen(socket_desc, 2);

    return socket_desc;
}

