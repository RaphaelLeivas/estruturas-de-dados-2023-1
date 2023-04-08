#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 10

char* buf;

int sum_to_n(int num) {
  int i, sum = 0;
  for (i = 1; i <= num; i++) sum += i;
  return sum;
}

void printSum() {
  char line[LINE_LENGTH];
  printf("enter a number:\n");
  fgets(line, LINE_LENGTH, stdin);
  if (line != NULL) strtok(line, "\n");
  sprintf(buf, "sum=%d", sum_to_n(atoi(line)));
  printf("%s\n", buf);
}

int main(void) {
  buf = malloc(LINE_LENGTH * sizeof(char));

  printSum();
  return 0;
}
