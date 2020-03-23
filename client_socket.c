#include <fcntl.h>
#include <poll.h>

#include "network.h"

char *HOST = "tec.skotos.net";
char *PORT = "6730";
int RECVBUFFMAX = 1024;

enum {
    MAX_SOCKETS = 50
};

struct pollfd pm_fda[MAX_SOCKETS];
int num_active = 0;

void pm_add(int sockfd, short events) {
    pm_fda[num_active].fd = sockfd;
    pm_fda[num_active].events = events;
    num_active++;
}

int pm_poll(int timeout) {
    int num_events = poll(pm_fda, num_active, timeout);  
    if (num_events == -1)
	perror("pm_poll: poll: ");

    return num_events;
}
//	for (int i = 0; i < num_active; i++) {
//	    if (pm_fda[i].revents & POLLIN) {
//		sfds[sock_index] = pm_fda[i].fd; 
//		sock_index++;
//		continue;
//	    } else if (pm_fda[i].revents & POLLOUT) {
//		sfds[sock_index] = pm_fda[i].fd; 
//		sock_index++;
//		continue;
//	    }
	    // NEEDS ERROR
//	}
 //   }
}

int main() {
    int return_status = 0;
    int sockfd;
    if ((sockfd = tcp_socket(HOST, PORT)) == -1) {
	fprintf(stderr, "tcp_socket failed.");
    }
    // Set socket to non-blocking
    fcntl(sockfd, F_SETFL, O_NONBLOCK);
    
    int ret_socks[10];
    pm_add(sockfd, POLLIN | POLLOUT);
    int num_events = pm_poll(1000, ret_socks);
    if (num_events > 0) {

    }
    
    return 0;
}
