#include "../include/NumExp.hpp"

NumExp::NumExp(std::string exp) {
    this->exp = exp;
    this->size = exp.length();
}

NumExp::~NumExp() {}

void NumExp::print() { std::cout << this->exp << std::endl; }

float NumExp::computeResult() {
    Stack* stack = new Stack(this->size);

    for (int i = 0; i < this->size; ++i) {
        
    }
}