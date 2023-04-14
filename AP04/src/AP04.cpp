#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include "../include/Stack.hpp"

#define STACK_SIZE 10

int main(int argc, char** argv) {
    int RANDOM_NUMBERS[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Stack* s = new Stack(STACK_SIZE);

    s->push(RANDOM_NUMBERS[0]);
    s->push(RANDOM_NUMBERS[1]);
    s->push(RANDOM_NUMBERS[2]);

    s->pop();
    s->pop();

    s->push(RANDOM_NUMBERS[7]);
    s->push(RANDOM_NUMBERS[8]);
    s->push(RANDOM_NUMBERS[9]);

    s->pop();
    s->pop();
    s->pop();
    s->pop();

    s->push(RANDOM_NUMBERS[4]);
    s->push(RANDOM_NUMBERS[5]);

    s->pop();
    s->pop();

    delete s;
    return 0;
}
