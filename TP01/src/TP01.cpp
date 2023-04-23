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

    NumExp* exp = new NumExp("( ( ( ( 4.771053 ) / ( 8.509878 ) ) + ( ( 2.799444 ) - ( 6.606407 ) ) ) - ( ( 3.703479 ) / ( 6.146766 ) ) )" );
    // NumExp* exp = new NumExp("4 + 8 * 5 - 44 / 11" );

    exp->toPostfix();
    exp->print();
    std::cout << std::setprecision(6) << std::fixed << exp->computeExpression() << std::endl;

    delete exp;

    return 0;
}