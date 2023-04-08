#include <stdio.h>
#include <stdlib.h>

#define MATRIX_DIMENSION 128

int main(void) {
  int** p = malloc(sizeof(int*) * MATRIX_DIMENSION);
  int i = 0;

  while (i < MATRIX_DIMENSION) {
    p[i] = malloc(sizeof(int) * MATRIX_DIMENSION);
    ++i;
  }

  return (0);
}
