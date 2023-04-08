#include <stdio.h>
#include <stdlib.h>

#define VECTOR_SIZE 10

int main(int argc, char** argv){
  int i;
  int a[VECTOR_SIZE];
  for (i = 0; i < VECTOR_SIZE; i++)
    a[i] = i;
    
  for (i = 0; i < VECTOR_SIZE; i++){
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}


