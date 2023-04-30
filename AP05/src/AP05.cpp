#include <stdio.h>
#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <string>

// file management
#include <getopt.h>

#include "../include/BinaryTree.hpp"

#define debug(a) std::cout << a << std::endl

void parse_args(int argc, char** argv) {
    int c;
    while ((c = getopt(argc, argv, "f:")) != EOF) {
    }
}

int main(int argc, char** argv) {
    // parse_args(argc, argv);

    BinaryTree* tree = new BinaryTree();

    tree->insert(5);

    tree->insert(3);
    tree->insert(2);
    tree->insert(1);

    tree->insert(4);

    tree->insert(7);
    tree->insert(6);

    tree->walk(WALK_TYPES::PRE_ORDER);

    delete tree;

    return 0;
}