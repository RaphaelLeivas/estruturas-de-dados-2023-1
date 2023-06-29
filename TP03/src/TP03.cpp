#include <stdio.h>
#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <string>

// file management
// #include <getopt.h>

#include <fstream>

#include "../include/BinaryTree.hpp"
#include "../include/LinkedList.hpp"

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

    int valuesToInsert[6] = {5, 33, 22, 5, 4, 100};
    int size = sizeof(valuesToInsert) / sizeof(valuesToInsert[0]);

    LinkedList list = LinkedList();


    for (int i = 0; i < size; ++i) {
        NodeItem newItem = NodeItem();
        newItem.setFrequency(valuesToInsert[i]);

        // if (i == 0) {
        //     list.insertStart(newItem);
        // } else if (i == size - 1) {
            list.insertEnd(newItem);
        // } else {
        //     list.insert(newItem, i);
        // }
    }

    for (int i = 0; i < size; ++i) {
        NodeItem newItem = NodeItem();
        newItem.setFrequency(valuesToInsert[i] * 100);
        list.setItem(newItem, i + 1);
    }

    list.remove(5);
    list.print();
    debug(list.getItem(5).getFrequency());

    return 0;
}