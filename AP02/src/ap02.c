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

static int selectedOperation = -1;

#define OP_FACTORIAL 0
#define OP_FIBONACCI 1

void parse_args(int argc, char **argv)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc e argv
// Saida: selectedOperation
{
  // variaveis externas do getopt
  extern char *optarg;
  extern int optind;

  // variavel auxiliar
  int c;

  // inicializacao variaveis globais para opcoes
  selectedOperation = -1;

  // getopt - letra indica a opcao, : junto a letra indica parametro
  while ((c = getopt(argc, argv, "smtc:p:x:y:lh")) != EOF) {
    printf("%s\n", "------");
    printf("%d", c);
    printf("%s\n", "-------");
    switch (c) {
      case 'a':
        selectedOperation = OP_FACTORIAL;
        break;
      case 'b':
        selectedOperation = OP_FIBONACCI;
        break;
      default:
        exit(1);
    }
  }
}

int main(int argc, char **argv) {
  int64_t before, after, diff;

  before = getUnixTimestamp(MICROSECONDS_OPTION);
  getRecursiveFibonacci(30);
  after = getUnixTimestamp(MICROSECONDS_OPTION);
  diff = after - before;

  printf("%" PRId64 "\n", diff);

  return 0;

  // struct rusage start, end;

  // struct timespec tp;
  // int result = clock_gettime(CLOCK_MONOTONIC, &tp);
  // printf("  tp.tv_sec %.06f tp.tv_nsec %.06f sec system\n", tp.tv_sec,
  //        tp.tv_nsec);

  // getrusage(RUSAGE_SELF, &start);
  // printf("%d", getRecursiveFibonacci(25));
  // getrusage(RUSAGE_SELF, &end);

  // printf("getRecursiveFibonacci stats:\n");
  // printf("  CPU time: %.06f sec user, %.06f sec system\n",
  //        diffUserTime(&start, &end), diffSystemTime(&start, &end));

  // getrusage(RUSAGE_SELF, &start);
  // loopFunc1(NUM_ITERS);
  // getrusage(RUSAGE_SELF, &end);

  // printf("loopFunc2 stats:\n");
  // printf("  CPU time: %.06f sec user, %.06f sec system\n",
  //        diffUserTime(&start, &end), diffSystemTime(&start, &end));

  // printf("\n");
  // printf("%d", selectedOperation);

  // printf("%s", "Factorial = ");
  // printf("%d", getRecursiveFibonacci(10));

  // printf("\n");

  // conclui registro de acesso
  return 0;
}
