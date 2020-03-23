#ifndef _NETWORK_H
#define _NETWORK_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

int socket_tcp(char *host, char *port);
static int _connect(struct addrinfo *ai_res);
int sendall(int sockfd, char *buff, int *len);

#endif
