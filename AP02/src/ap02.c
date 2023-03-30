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

// #include "../include/customTime.h"
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

  // int64_t before, after, diff;
  // struct rusage start, end;

  // getrusage(RUSAGE_SELF, &start);
  // before = getUnixTimestamp(NANOSECONDS_OPTION);

  if (opescolhida == OP_FIBONACCI) {
    printf("Running OP_FIBONACCI \n");
    getRecursiveFibonacci(40);
    getIteractiveFibonacci(400);
  } else if (opescolhida == OP_FACTORIAL) {
    printf("Running OP_FACTORIAL \n");
    getRecursiveFactorial(40);
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
