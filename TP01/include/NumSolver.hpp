#ifndef NUM_SOLVER_HPP
#define NUM_SOLVER_HPP

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "NumExp.hpp"

const std::string INPUT_INFIX_LABEL = "INFIXA";
const std::string INPUT_POSTFIX_LABEL = "POSFIXA";

class NumSolver {
   public:
    NumSolver();
    ~NumSolver();
    double solve();
    void convertToInfix();
    void convertToPostfix();
    void save(std::string);
    void print();
    NumExp* getSavedExp();
    void setSavedExp(NumExp*);

   private:
    NumExp* savedExp;
};

#endif