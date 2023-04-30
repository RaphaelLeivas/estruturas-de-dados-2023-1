#include <stdio.h>
#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <string>

// file management
#include <getopt.h>

#include "../include/Item.hpp"
#include "../include/Node.hpp"

#define debug(a) std::cout << a << std::endl

void parse_args(int argc, char** argv) {
    int c;
    while ((c = getopt(argc, argv, "f:")) != EOF) {
    }
}

int main(int argc, char** argv) {
    // parse_args(argc, argv);

    Node<double>* node1 = new Node<double>();

    node1->getItem()->print();
    node1->getItem()->setValue(10.552);
    node1->getItem()->print();

    delete node1;

    return 0;
}