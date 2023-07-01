#include <stdio.h>
#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <string>

// file management
#include <getopt.h>

#include <fstream>

#include "../include/NumSolver.hpp"

std::string fileToComp;

void parse_args(int argc, char** argv) {
    int c;
    while ((c = getopt(argc, argv, "f:")) != EOF) {
        if (c == 'f') {
            fileToComp = optarg;
        }
    }
}

int main(int argc, char** argv) {
    parse_args(argc, argv);

    NumSolver* numSolver = new NumSolver();

    std::ifstream input(fileToComp);
    std::string line;

    while (std::getline(input, line)) {
        std::string command = numSolver->parseCommandFromLine(&line);

        // protecao espacos e linhas vazias no arquivo de entrada
        if (command == "" || command == " ") {
            continue;
        }

        if (command == INPUT_READ_COMMAND) {
            numSolver->save(line);  // salva o restante que esta na linha
        } else if (command == INPUT_POSTFIX_COMMAND) {
            numSolver->convertToPostfix();
        } else if (command == INPUT_INFIX_COMMAND) {
            numSolver->convertToInfix();
        } else if (command == INPUT_SOLVE_COMMAND) {
            numSolver->solve();
        }
    }

    delete numSolver;
    return 0;
}