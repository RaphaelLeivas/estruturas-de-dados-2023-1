#include <stdio.h>
#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <string>

// file management
// #include <getopt.h>

#include <fstream>

#include "../include/BinaryTree.hpp"

std::string inputFilePath;

// void parse_args(int argc, char** argv) {
//     int c;
//     while ((c = getopt(argc, argv, "f:")) != EOF) {
//         if (c == 'f') {
//             inputFilePath = optarg;
//         }
//     }
// }

int main(int argc, char** argv) {
    // parse_args(argc, argv);

    int valuesToInsert[7] = {5, 5, 4, 2, 3, 1, 70};
    int size = sizeof(valuesToInsert)/sizeof(valuesToInsert[0]);

    BinaryTree tree = BinaryTree();

    for (int i = 0; i < size; ++i) {
        NodeItem newItem = NodeItem();
        newItem.setFrequency(valuesToInsert[i]);

        tree.insert(newItem);
    }

    tree.remove(5);

    tree.walk(WALK_TYPES::PRE_ORDER);

    return 0;
}