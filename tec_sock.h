#ifndef _TEC_SOCK_H
#define _TEC_SOCK_H

#include "network.h"
#include "slog.h"

typedef struct tsock tsock;

tsock *new_tsock(short sid);
int tsock_fd(tsock *ts);
short tsock_sid(tsock *ts);
int close_tsock(tsock *ts);

#endif
