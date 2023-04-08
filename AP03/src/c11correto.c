#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MSG_LENGTH 9

int main(void) {
  char *msg = malloc(MSG_LENGTH);
  strcpy(msg, "Holberton");
  msg[0] = 'R';
  printf("%ld, %s\n", (long)getpid(), msg);
  return (0);
}
