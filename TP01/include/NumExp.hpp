#ifndef NUM_EXP_HPP
#define NUM_EXP_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

#include "Stack.hpp"

#define debug(a) std::cout << a << std::endl

enum class ExpType { INFIX, POSTFIX };

// NumExp é essencialmente uma string com alguns metodos adicionados
// usa ele para manipular as expressoes de forma mais modularizada

class NumExp {
   public:
    NumExp(std::string exp, ExpType expType);
    ~NumExp();
    double computeExpression();
    void convertToInfix();
    void convertToPostfix();
    bool isValid();
    void print();

   private:
    std::string exp;
    ExpType expType;
    int size;
    void setExpType(ExpType expType);
    void setExp(std::string exp);

    // metodos abaixo poderiam ser abstraidos
    bool isOperator(std::string);
    double computeOperation(char, double, double);
    std::string getPostfix(std::string);
    std::string getInfix(std::string);
};

#endif