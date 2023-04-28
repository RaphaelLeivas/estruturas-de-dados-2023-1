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

    NumExp* exp = new NumExp("6.245338  5.326499  7.733752  -  1.093085  /  4.995825  /  5.954532  *  *  4.752909  9.616572  *  8.550690  -  7.844262  5.471297  +  3.332128  7.449099  +  -  -  -  6.671527  0.051021  *  /  0.025147  9.360934  /  0.479166  +  +  7.084182  8.068251  -  8.999193  4.021101  +  +  6.038406  +  * ", ExpType::POSTFIX);
    // NumExp* exp = new NumExp("10 20 *" );
    // NumExp* exp = new NumExp("4 + 8 * 5 - 44 / 11" );

    // exp->getInfix();
    // exp->print();
    // exp->getInfix();
    exp->print();

    std::cout << std::fixed;
    std::cout.precision(6);
    std::cout << exp->computeExpression() << std::endl;

    delete exp;

    return 0;
}