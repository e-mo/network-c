#include "slog.h"

FILE *slogfd;
int init = 0;

int init_slog(char *filename) {
    if (!init) {
	if ((slogfd = fopen(filename, "w")) == NULL) {
	    fprintf(stderr, "init_slog(char *filename) failed to open \"%s\"");
	    return -1;
	}
	init = 1;
    }
}

int slog(char *message) {
    if (!init) {
	fprintf(stderr, "slog: slog must be initialised before use.");
	return -1;
    }
    return fprintf(slogfd, "%s:> %s\n", _get_tstamp(), message);
}

char *_get_tstamp(void) {
    time_t raw_time;
    struct tm *loc_time;
    static char str_time[9];

    time(&raw_time);
    loc_time = localtime(&raw_time);

    int hour = loc_time->tm_hour;
    int min = loc_time->tm_min;
    int sec = loc_time->tm_sec;

    sprintf(str_time, "%02d:%02d:%02d", hour, min, sec);
    return str_time;
}

int close_slog(void) {
    if (!init) {
	fprintf(stderr, "close_slog: no open .slog file.");
	return -1;
    }
    return fclose(slogfd);
}
