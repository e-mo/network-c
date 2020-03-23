#include "tec_sock.h"

char *HOST = "tec.skotos.net";
char *PORT = "6730";
int next_sid = 0;

struct tsock {
    int fd;
    short sid;
};

tsock *new_tsock(short sid) {
    tsock *new_ts = malloc(sizeof(new_ts));
    socket_tcp(HOST, PORT);
    int sockfd = socket_tcp(HOST, PORT); 
    if (sockfd == -1)
	slog("new_tsock: socket_tcp() returned -1");

    new_ts->fd = sockfd;
    new_ts->sid = sid;

    return new_ts;
}

int tsock_fd(tsock *ts) {
    return ts->fd;
}

short tsock_sid(tsock *ts) {
    return ts->sid;
}

int close_tsock(tsock *ts) {
    int rval = close(ts->fd);
    free(ts);

    return rval;
}
