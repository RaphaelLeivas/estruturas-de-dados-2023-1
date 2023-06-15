#include "customTime.h"

int64_t getUnixTimestamp(int option) {
  struct timespec tms;

  if (clock_gettime(CLOCK_REALTIME, &tms)) {
    return -1;
  }

  int64_t result = 0;

  switch (option) {
    case MICROSECONDS_OPTION: {
      int64_t micros = tms.tv_sec * 1000000;

      /* Add os microssegundos */
      micros += tms.tv_nsec / 1000;

      /* arrendondamento */
      if (tms.tv_nsec % 1000 >= 500) {
        ++micros;
      }

      result = micros;
      break;
    }

    case NANOSECONDS_OPTION: {
      int64_t nanos = tms.tv_sec * 1000000000;

      /* Add os nanossegundos */
      nanos += tms.tv_nsec;

      result = nanos;
      break;
    }

    case MILISECONDS_OPTION:
    default: {
      int64_t millis = tms.tv_sec * 1000;

      /* Add os milissegundos */
      millis += tms.tv_nsec / 1000000;

      /* arrendondamento */
      if (tms.tv_nsec % 1000000 >= 500000) {
        ++millis;
      }

      result = millis;
      break;
    }
  }

  return result;
};

float getUserTimeDiff(struct rusage *start, struct rusage *end) {
  return (end->ru_utime.tv_sec - start->ru_utime.tv_sec) +
         1e-6 * (end->ru_utime.tv_usec - start->ru_utime.tv_usec);
};

float getSystemTimeDiff(struct rusage *start, struct rusage *end) {
  return (end->ru_stime.tv_sec - start->ru_stime.tv_sec) +
         1e-6 * (end->ru_stime.tv_usec - start->ru_stime.tv_usec);
};