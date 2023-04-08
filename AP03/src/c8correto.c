#include <stdint.h>
#include <stdlib.h>

#define DESTINATION_LENGTH 27
#define SOURCE_LENGTH 27

int main() {
  char* destination = calloc(DESTINATION_LENGTH, sizeof(char));
  char* source = malloc(SOURCE_LENGTH * sizeof(char));

  for (uint8_t i = 0; i < SOURCE_LENGTH; i++) {
    *(destination + i) = *(source + i); 
  }

  free(destination);
  free(source);
  return 0;
}
