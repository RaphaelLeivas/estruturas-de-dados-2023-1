#include <stdio.h>
#include <stdlib.h>

#define MATRIX_ROWS 10
#define MATRIX_COLUMNS 100

int main(int argc, char** argv) {
  int i;
  int** a = malloc(MATRIX_ROWS * sizeof(int*));

  for (i = 0; i < MATRIX_ROWS; i++) {
    a[i] = malloc(sizeof(int) * MATRIX_COLUMNS);
  }
  
  free(a);
  return 0;
}
