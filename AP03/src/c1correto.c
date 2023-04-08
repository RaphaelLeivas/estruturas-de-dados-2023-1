#include <stdio.h>
#include <stdlib.h>

#define VECTOR_SIZE 10

int main(int argc, char** argv) {
  int i;
  int* a = malloc(sizeof(int) * VECTOR_SIZE);
  if (!a) return -1; /*malloc failed*/
  for (i = 0; i < VECTOR_SIZE; i++) {
    a[i] = i;
  }
  free(a);
  return 0;
}
