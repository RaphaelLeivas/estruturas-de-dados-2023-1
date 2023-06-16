#ifndef CUSTOM_TIME_H
#define CUSTOM_TIME_H

#include <sys/resource.h>
#include <time.h>
#include <inttypes.h>

#define MILISECONDS_OPTION 0
#define MICROSECONDS_OPTION 1
#define NANOSECONDS_OPTION 2

int64_t getUnixTimestamp(int option);

// funções abaixo extraidas de https://www.delftstack.com/howto/c/getrusage-example-in-c/
float getUserTimeDiff(struct rusage *start, struct rusage *end);
float getSystemTimeDiff(struct rusage *start, struct rusage *end);

#endif
