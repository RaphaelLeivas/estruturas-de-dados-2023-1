#include <stdint.h>
#include <stdlib.h>

int main() {
  char* alphabet = calloc(26, sizeof(char));

  for (uint8_t i = 0; i < 26; i++) {
    *(alphabet + i) = 'A' + i;
  }
  *(alphabet + 26) = '\0';  // null-terminate the string?

  for (int i = 0; i < 26; i++) {
    printf("%c", alphabet[i]);
  }

  free(alphabet);
  return 0;
}
