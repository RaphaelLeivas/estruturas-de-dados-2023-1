#include <stdio.h>
#include <stdlib.h>

int actual_calc(int a, int b) {
  int c;

  if (b == 0) return 0;

  c = a / b;
  return c;
}

int calc() {
  int a;
  int b;
  a = 13;
  b = 0;
  return actual_calc(a, b);
}

int main() {
  calc();
  return 0;
}
