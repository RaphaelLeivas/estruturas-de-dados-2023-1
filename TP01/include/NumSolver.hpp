#ifndef NUM_SOLVER_HPP
#define NUM_SOLVER_HPP

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "NumExp.hpp"

const std::string INPUT_INFIX_COMMAND = "INFIXA";
const std::string INPUT_POSTFIX_COMMAND = "POSFIXA";
const std::string INPUT_READ_COMMAND = "LER";
const std::string INPUT_SOLVE_COMMAND = "RESOLVE";

class NumSolver {
   public:
    NumSolver();
    ~NumSolver();
    double solve();
    void convertToInfix();
    void convertToPostfix();
    void save(std::string);
    std::string parseCommandFromLine(std::string*);

    NumExp* getSavedExp();
    void setSavedExp(NumExp*);
    void printSavedExp();

   private:
    NumExp* savedExp;
};

#endif