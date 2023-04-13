#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include "../include/Stack.hpp"

#define STACK_SIZE 5

int main(int argc, char** argv) {
    Stack* s = new Stack(STACK_SIZE);

    delete s;
    return 0;
}
