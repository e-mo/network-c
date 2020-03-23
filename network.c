#include "network.h"

int socket_tcp(char *host, char *port) {
    struct addrinfo ai_hints = {
	.ai_family = AF_UNSPEC,
	.ai_socktype = SOCK_STREAM
    };
    struct addrinfo *ai_res;
    int sockfd;

    int rval;
    if ((rval = getaddrinfo(host, port, &ai_hints, &ai_res)) != 0) {
	fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(rval));
	fflush(stdout);
	return -1;
    }

    return sockfd = _connect(ai_res); 
}

static int _connect(struct addrinfo *ai_res) {
    int sockfd;
    struct addrinfo *ai_p;
    for (ai_p = ai_res; ai_p != NULL; ai_p = ai_p->ai_next) {
	sockfd = socket(
		ai_p->ai_family, 
		ai_p->ai_socktype,
		ai_p->ai_protocol);

	if (sockfd == -1) {
	    perror("tcp_socket: socket");
	    continue;
	} else if (connect(sockfd, ai_p->ai_addr, ai_p->ai_addrlen) == -1) {
	    close(sockfd);
	    perror("tcp_socket: connect");
	    sockfd = -1;
	    continue;
	}
    }
    return sockfd;
}

int sendall(int sockfd, char *buff, int *len) {
    int total = 0;
    int remaining = *len;
    int num_sent;

    while(total < *len) {
	num_sent = send(sockfd, buff + total, remaining, 0);
	if (num_sent == -1)
	    break;
	total += num_sent;	
	remaining -= num_sent;
    }

    // Return total sent in len variable
    *len = total; 

    // return -1 on failure
    return num_sent == -1 ? -1 : 0;
}
