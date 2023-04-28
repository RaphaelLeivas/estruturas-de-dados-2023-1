#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <iomanip>
#include <string>

// file management
#include <fstream>

#include "../include/NumSolver.hpp"

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

    NumSolver* numSolver = new NumSolver();
    numSolver->save("INFIXA 3 + 4");

    // NumExp* exp = new NumExp("3 4 + +", ExpType::INFIX);
    // NumExp* exp = new NumExp("10 20 *" );
    // NumExp* exp = new NumExp("4 + 8 * 5 - 44 / 11" );

    // exp->getInfix();
    // exp->print();
    // exp->getInfix();
    // numSolver->print();

    // std::cout << std::fixed;
    // std::cout.precision(6);
    // std::cout << numSolver->solve() << std::endl;

    // delete exp;
    delete numSolver;

    return 0;
}