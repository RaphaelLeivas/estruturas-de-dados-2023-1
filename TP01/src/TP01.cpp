#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// file management
#include <fstream>
#include <string>

#include "../include/Stack.hpp"
#include "../include/NumExp.hpp"

#define STACK_SIZE 10


int main(int argc, char** argv) {
    NumExp* sum = new NumExp((char*)"Testeee", 7);
    sum->print();

    std::ifstream file;
    file.open("../texto.txt", std::ios::in);
    std::string text;

    if (getline(file, text)) {
        std::cout << text << std::endl;
    }

    delete sum;
    return 0;
}