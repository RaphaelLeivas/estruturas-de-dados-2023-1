#ifndef NUM_EXP_HPP
#define NUM_EXP_HPP

#include <iostream>
#include <stdexcept>

#define EXP_MAX_LENGTH 1000

// NumExp é essencialmente um vetor de caracteres 
// usa ele para manipular as expressoes de forma mais modularizada

class NumExp {
   public:
    NumExp(char* const exp, int size);
    ~NumExp();
    void toPostfix();
    void toInfix();
    float computeResult();
    static bool isValid();
    void print();

   private:
    char* exp;
    int size;
};

#endif