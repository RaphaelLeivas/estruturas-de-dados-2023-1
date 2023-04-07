#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_INT 10000

unsigned int getRecursiveFibonacci(unsigned int n) {
  if (n < 0) {
    return 0;
  }

  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }

  return getRecursiveFibonacci(n - 1) + getRecursiveFibonacci(n - 2);
}

unsigned int getIteractiveFactorial(unsigned int n) {
  if (n < 0) {
    return 0;
  }

  int factorial = 1;
  for (int i = 1; i <= n; i++) {
    factorial *= i;
  }

  return factorial;
}

int multiplyIntegers(int n1, int n2) {
  return n1 * n2;
}

unsigned int getIteractiveFactorialByPointer(unsigned int* n) {
  int num_value = *n;
  if (num_value < 0) {
    return 0;
  }

  int factorial = 1;
  for (int i = 1; i <= num_value; i++) {
    factorial = multiplyIntegers(i, factorial);
  }

  return factorial;
}

int main(int argc, char **argv) {
  int num = 12;
  unsigned int* num_ptr = &num;

  unsigned int factorial = getIteractiveFactorialByPointer(num_ptr);
  printf("\nPrinting factorial now! %d\n", factorial);

  unsigned int fibonacci = getRecursiveFibonacci(num);
  printf("\nPrinting fibonacci now! %d\n", fibonacci);

  return 0;
}
