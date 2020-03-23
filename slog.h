#ifndef _SLOG_H
#define _SLOG_H

#include <stdio.h>
#include <time.h>

int init_slog(char *filename);
int slog(char *message);
char *_get_tstamp(void);
int close_slog(void);

#endif
