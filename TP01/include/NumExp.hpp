#ifndef NUM_EXP_HPP
#define NUM_EXP_HPP

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "Stack.hpp"

#define debug(a) std::cout << a << std::endl

enum class ExpType { INFIX, POSTFIX };

// NumExp é essencialmente uma string com alguns metodos adicionados
// usa ele para manipular as expressoes de forma mais modularizada

class NumExp {
   public:
    NumExp(std::string exp, ExpType expType);
    ~NumExp();
    bool isValid();
    void print();
    double computeExpression();
    void setExpType(ExpType expType);
    void setExp(std::string exp);
    ExpType getExpType();
    std::string getExp();
    void toPostfix();
    void toInfix();

   private:
    std::string exp;
    ExpType expType;

    // metodos abaixo poderiam ser abstraidos
    bool isOperator(std::string);
    double computeOperation(char, double, double);
};

#endif