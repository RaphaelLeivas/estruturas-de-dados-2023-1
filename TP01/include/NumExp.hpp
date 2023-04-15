#ifndef NUM_EXP_HPP
#define NUM_EXP_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <regex>

#include "Stack.hpp"
#include "CircularQueue.hpp"

#define debug(a) std::cout << a << std::endl

// NumExp é essencialmente uma string com alguns metodos adicionados
// usa ele para manipular as expressoes de forma mais modularizada

class NumExp {
   public:
    NumExp(std::string exp);
    ~NumExp();
    void toPostfix();
    void toInfix();
    float computeExpression();
    static bool isValid();
    void print();

   private:
    std::string exp;
    int size;
    bool isOperator(std::string);
    float computeOperation(char, float, float);
};

#endif