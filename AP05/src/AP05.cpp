#include <stdio.h>
#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <string>

// file management
#include <getopt.h>

#include "../include/Item.hpp"

#define debug(a) std::cout << a << std::endl

void parse_args(int argc, char** argv) {
    int c;
    while ((c = getopt(argc, argv, "f:")) != EOF) {
    }
}

int main(int argc, char** argv) {
    // parse_args(argc, argv);

    Item<double>* item1 = new Item<double>(0, 52.2);
    Item<double>* item2 = new Item<double>(1, 65.3);

    item1->print();
    item2->print();

    delete item1;
    delete item2;

    return 0;
}