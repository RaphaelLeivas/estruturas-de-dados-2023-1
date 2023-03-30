//---------------------------------------------------------------------
// Arquivo	: ap02.c
// Conteudo	: implementacao Atividade Pratica 02 - recursão
// Autor		: Raphael Henrique Braga Leivas (raphaelbleivas@ufmg.br)
// Histórico	: 2023-03-28 - arquivo criado
//---------------------------------------------------------------------

#include <getopt.h>
#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/customTime.h"
#include "../include/factorial.h"
#include "../include/fibonacci.h"
#include "../include/msgassert.h"

#define OP_FIBONACCI 1
#define OP_FACTORIAL 2

// variaveis globais para opcoes
static int opescolhida;

void parse_args(int argc, char **argv) {
  // variavel auxiliar
  int c;

  // inicializacao variaveis globais para opcoes
  opescolhida = -1;

  while ((c = getopt(argc, argv, "ab")) != EOF) {
    switch (c) {
      case 'a':
        opescolhida = OP_FIBONACCI;
        break;
      case 'b':
      default:
        opescolhida = OP_FACTORIAL;
    }
  }
}

int main(int argc, char **argv) {
  parse_args(argc, argv);

  int A[] = {1, 3, 5, 10, 15, 20, 25, 30, 35, 40};
  int B[] = {100, 300, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000};
  int A_length = sizeof(A) / sizeof(A[0]);

  int64_t unixTimestampRecursive[A_length];
  int64_t unixTimestampIteractive[A_length];

  float userTimeRecursive[A_length];
  float userTimeIteractive[A_length];
  float systemTimeIteractive[A_length];
  float systemTimeRecursive[A_length];

  for (int i = 0; i < A_length; i++) {
    if (opescolhida == OP_FIBONACCI) {
      // int64_t before = getUnixTimestamp(MICROSECONDS_OPTION);

      struct rusage start, end;

      getrusage(RUSAGE_SELF, &start);
      getRecursiveFibonacci(A[i]);
      getrusage(RUSAGE_SELF, &end);

      userTimeRecursive[i] = getUserTimeDiff(&start, &end);
      systemTimeRecursive[i] = getSystemTimeDiff(&start, &end);

      // int64_t after = getUnixTimestamp(MICROSECONDS_OPTION);
      // unixTimestampRecursive[i] = after - before;

      // before = getUnixTimestamp(MICROSECONDS_OPTION);
      getrusage(RUSAGE_SELF, &start);
      getIteractiveFibonacci(A[i]);
      getrusage(RUSAGE_SELF, &end);

      // after = getUnixTimestamp(MICROSECONDS_OPTION);
      // unixTimestampIteractive[i] = after - before;

      userTimeIteractive[i] = getUserTimeDiff(&start, &end);
      systemTimeIteractive[i] = getSystemTimeDiff(&start, &end);
    } else if (opescolhida == OP_FACTORIAL) {
      int64_t before = getUnixTimestamp(MICROSECONDS_OPTION);

      // struct rusage start, end;

      // getrusage(RUSAGE_SELF, &start);
      getRecursiveFactorial(B[i]);
      // getrusage(RUSAGE_SELF, &end);

      // userTimeRecursive[i] = getUserTimeDiff(&start, &end);
      // systemTimeRecursive[i] = getSystemTimeDiff(&start, &end);

      int64_t after = getUnixTimestamp(MICROSECONDS_OPTION);
      unixTimestampRecursive[i] = after - before;

      before = getUnixTimestamp(MICROSECONDS_OPTION);
      // getrusage(RUSAGE_SELF, &start);
      getIteractiveFactorial(B[i]);
      // getrusage(RUSAGE_SELF, &end);

      after = getUnixTimestamp(MICROSECONDS_OPTION);
      unixTimestampIteractive[i] = after - before;

      // userTimeIteractive[i] = getUserTimeDiff(&start, &end);
      // systemTimeIteractive[i] = getSystemTimeDiff(&start, &end);
    }
  }

  for (int i = 0; i < A_length; i++) {
    printf("Iteractive unix = %" PRId64 "", unixTimestampIteractive[i]);
    printf("     ");
    printf("recursive unix= %" PRId64 "", unixTimestampRecursive[i]);
    printf("\n");
  }

  // after = getUnixTimestamp(NANOSECONDS_OPTION);
  // getrusage(RUSAGE_SELF, &end);

  // printf("\n\n\n");

  // printf("  CPU time: %.06f sec user, %.06f sec system\n",
  //        getUserTimeDiff(&start, &end), getSystemTimeDiff(&start, &end));

  // diff = after - before;

  // printf("\n\n\n");

  // printf("Unix timestamp time: %" PRId64 "\n", diff);

  return 0;
}
