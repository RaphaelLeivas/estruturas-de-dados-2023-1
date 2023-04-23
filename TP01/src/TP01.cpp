#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <iomanip>
#include <string>

// file management
#include <fstream>

#include "../include/NumExp.hpp"

int main(int argc, char** argv) {
    // std::ifstream input("/mnt/c/dev/estruturas-de-dados-2023-1/TP01/TP1entrada/entdouble.s1.n5.i.in");
    // std::ifstream input("/mnt/c/dev/estruturas-de-dados-2023-1/TP01/input.txt");
    // std::string line;

    // while (std::getline(input, line)) {
    //     NumExp* exp = new NumExp(line);
    //     float result = exp->computeExpression();

    //     std::cout << result << std::endl;

    //     delete exp;
    // }

    NumExp* exp = new NumExp("5.946317  1.106634  6.917778  *  7.021876  5.427541  /  -  8.515828  0.091471  /  *  - " );
    // NumExp* exp = new NumExp("10 20 *" );
    // NumExp* exp = new NumExp("4 + 8 * 5 - 44 / 11" );

    exp->toInfix();
    exp->print();
    exp->toPostfix();

    std::cout << std::fixed;
    std::cout.precision(6);
    std::cout << exp->computeExpression() << std::endl;

    delete exp;

    return 0;
}