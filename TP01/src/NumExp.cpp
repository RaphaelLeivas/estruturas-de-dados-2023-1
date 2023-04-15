#include "../include/NumExp.hpp"

NumExp::NumExp(char* const exp, int size) {
    this->exp = exp;
    this->size = size;
}

NumExp::~NumExp() {}

void NumExp::print() {
    for (int i = 0; i < size; ++i) {
        std::cout << this->exp[i];
    }
    std::cout << std::endl;
}
