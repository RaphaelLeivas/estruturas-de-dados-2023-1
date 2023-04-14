#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include "../include/Stack.hpp"

#define STACK_SIZE 5

int main(int argc, char** argv) {
    Stack* s = new Stack(STACK_SIZE);

    s->push(10);
    s->push(20);

    std::cout << "Stack value = " << s->pop() << std::endl;
    std::cout << "Stack value = " << s->pop() << std::endl;

    delete s;
    return 0;
}
