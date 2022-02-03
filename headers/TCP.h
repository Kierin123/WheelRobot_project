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

#define CHAR_IN_MESSAGE 100
#define CHAR_IN_ANSWER 2


int32_t socket_init(uint32_t _port);

#endif
