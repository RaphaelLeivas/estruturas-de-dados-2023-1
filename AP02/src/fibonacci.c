#include "fibonacci.h"

unsigned int getRecursiveFibonacci(unsigned int n) {
  if (n < 0) {
    erroAssert(n < 0,
               "Numero de Fibonacci deve ser maior ou igual a zero. Retornando "
               "n! = 0");
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

unsigned int getIteractiveFibonacci(unsigned int n) {
  if (n < 0) {
    erroAssert(n < 0,
               "Numero de Fibonacci deve ser maior ou igual a zero. Retornando "
               "n! = 0");
    return 0;
  }

  int fibonacciArray[n + 1];

  fibonacciArray[0] = 0;
  fibonacciArray[1] = 1;

  for (int i = 2; i <= n; i++) {
    fibonacciArray[i] = fibonacciArray[i - 1] + fibonacciArray[i - 2];
  }

  return fibonacciArray[n];
}

