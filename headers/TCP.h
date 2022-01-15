#ifndef _TCP_H
#define _TCP_H

#include <stdio.h>
#include <string.h>     //strlen
#include <stdlib.h>     //strlen
#include <sys/socket.h>
#include <arpa/inet.h>  //inet_addr
#include <unistd.h>	    //write
#include <sys/types.h>
#include <fcntl.h>

#define CHAR_IN_MESSAGE 30
#define CHAR_IN_ANSWER 2

int send_message(char *msg);
char *read_message(int *_socket_desc);

void socket_init(int _port);
void connection_handler(void *socket_desc);

#endif
