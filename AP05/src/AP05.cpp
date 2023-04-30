#include <stdio.h>
#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <string>

// file management
#include <getopt.h>

#include "../include/BinaryTree.hpp"
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

    Item<int> item0;
    item0.setKey(0);

    Item<int> item1;
    item1.setKey(1);

    Item<int> item2;
    item2.setKey(2);

    Item<int> item3;
    item3.setKey(3);

    Item<int> item4;
    item4.setKey(4);

    Item<int> item5;
    item5.setKey(5);

    Item<int> item6;
    item6.setKey(6);

    BinaryTree<int>* tree = new BinaryTree<int>();

    tree->insert(item0);
    tree->insert(item1);
    tree->insert(item2);
    tree->insert(item3);
    tree->insert(item4);
    tree->insert(item5);
    tree->insert(item6);

    delete tree;

    return 0;
}