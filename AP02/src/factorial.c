#include "factorial.h"

unsigned int getIteractiveFactorial(unsigned int n) {
  if (n < 0) {
    erroAssert(
        n < 0,
        "Fatorial de numeros negativos nao esta definido. Retornando n! = 0");
    return 0;
  }

  int factorial = 1;
  for (int i = 1; i <= n; i++) {
    factorial *= i;
  }

  return factorial;
}

unsigned int getRecursiveFactorial(unsigned int n) {
  // struct timespec tp;

  // int result = clock_gettime(CLOCK_MONOTONIC, &tp);

  if (n < 0) {
    erroAssert(
        n < 0,
        "Fatorial de numeros negativos nao esta definido. Retornando n! = 0");
    return 0;
  }

  // operação computacional intensa
  for (int i = 1; i < 1000; i++) {
    sin(1);
  };

  if (n == 0) {
    return 1;
  }
  return n * getRecursiveFactorial(n - 1);
}

