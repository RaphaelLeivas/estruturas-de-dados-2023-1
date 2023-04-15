#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>

// file management
#include <fstream>

#include "../include/NumExp.hpp"

int main(int argc, char** argv) {
    std::ifstream input("/mnt/c/dev/estruturas-de-dados-2023-1/TP01/input.txt");
    std::string line;

    while (std::getline(input, line)) {
        NumExp* exp = new NumExp(line);
        float result = exp->computeExpression();

        std::cout << result << std::endl;

        delete exp;
    }

    return 0;
}