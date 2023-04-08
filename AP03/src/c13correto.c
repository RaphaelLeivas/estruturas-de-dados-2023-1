#include <stdio.h>
#include <stdlib.h>

int main() {
  char *p;

  p = (char *)malloc(16 * sizeof(char));
  free(p);

  return 0;
}