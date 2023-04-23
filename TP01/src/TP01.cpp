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

    NumExp* exp = new NumExp("( ( ( ( 9.904341 ) + ( ( 5.733451 ) - ( 0.641665 ) ) ) - ( ( 2.165881 ) + ( 1.404730 ) ) ) - ( ( 5.732986 ) + ( ( 5.938726 ) - ( 8.993233 ) ) ) )" );
    // NumExp* exp = new NumExp("4 + 8 * 5 - 44 / 11" );

    exp->toPostfix();
    exp->print();
    std::cout << std::setprecision(6) << std::fixed << exp->computeExpression() << std::endl;

    delete exp;

    return 0;
}