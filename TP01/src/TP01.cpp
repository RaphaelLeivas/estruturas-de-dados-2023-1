#include <stdio.h>
#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <string>

// file management
#include <getopt.h>

#include <fstream>

#include "../include/NumSolver.hpp"

std::string inputFilePath;

void parse_args(int argc, char** argv) {
    int c;
    while ((c = getopt(argc, argv, "f:")) != EOF) {
        if (c == 'f') {
            inputFilePath = optarg;
        }
    }
}

int main(int argc, char** argv) {
    parse_args(argc, argv);

    std::cout << std::fixed;
    std::cout.precision(6);
    NumSolver* numSolver = new NumSolver();

    std::ifstream input(inputFilePath);
    std::string line;

    while (std::getline(input, line)) {
        std::string command = numSolver->parseCommandFromLine(&line);

        if (command == INPUT_READ_COMMAND) {
            numSolver->save(line);  // salva o restante que esta na linha
        } else if (command == INPUT_POSTFIX_COMMAND) {
            numSolver->convertToPostfix();
        } else if (command == INPUT_INFIX_COMMAND) {
            numSolver->convertToInfix();
        } else if (command == INPUT_SOLVE_COMMAND) {
            std::cout << numSolver->solve() << std::endl;
        } else {
            throw std::invalid_argument(
                "Unable to execute operation: command is invalid!");
        }
    }

    delete numSolver;
    return 0;
}