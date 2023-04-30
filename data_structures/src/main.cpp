#include <stdio.h>
#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <string>

// file management
#include <getopt.h>

#include "../include/Stack.hpp"

#define debug(a) std::cout << a << std::endl

void parse_args(int argc, char** argv) {
    int c;
    while ((c = getopt(argc, argv, "f:")) != EOF) {
    }
}

int main(int argc, char** argv) {
    parse_args(argc, argv);

    int number = 10;

    debug(number);

    Stack<int>* s = new Stack<int>(10);

    s->push(10);
    s->push(100);
    s->push(1000);

    debug(s->pop());
    debug(s->pop());
    debug(s->pop());
    // debug(s->pop());

    delete s;

    return 0;
}