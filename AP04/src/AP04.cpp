#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include "../include/Stack.hpp"
#include "../include/memlog.h"

#define STACK_SIZE 10

int main(int argc, char** argv) {
    int num = 100;
    char* filename =  "/mnt/c/dev/estruturas-de-dados-2023-1/AP04/tmp/log.out";

    // iniciar registro de acesso
    iniciaMemLog(filename);
    ativaMemLog();

    ESCREVEMEMLOG((long int)(&(num)),sizeof(int),123);

    finalizaMemLog();
    desativaMemLog();

    std::cout << num << std::endl;

    return 0;
}
