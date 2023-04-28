#include <stdio.h>
#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <string>

// file management
#include <fstream>

#include "../include/NumSolver.hpp"

int main(int argc, char** argv) {
    std::cout << std::fixed;
    std::cout.precision(6);
    NumSolver* numSolver = new NumSolver();

    std::ifstream input(
        "/mnt/c/dev/estruturas-de-dados-2023-1/TP01/TP1entrada/"
        "entdouble.s2.n5.p.in");

    std::string line;

    while (std::getline(input, line)) {
        std::string command = numSolver->parseCommandFromLine(&line);

        if (command == INPUT_READ_COMMAND) {
            numSolver->save(line); // salva o restante que esta na linha
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