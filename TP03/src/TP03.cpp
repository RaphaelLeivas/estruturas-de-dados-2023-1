#include <stdio.h>
#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <string>

// file management
#include <getopt.h>

#include <fstream>

#include "../include/BinaryTree.hpp"
#include "../include/LinkedList.hpp"

std::string fileToComp;
std::string fileToDecomp;

void parse_args(int argc, char** argv) {
    int c;
    while ((c = getopt(argc, argv, "c:d:")) != EOF) {
        if (c == 'c') {
            fileToComp = optarg;
        }
        if (c == 'd') {
            fileToDecomp = optarg;
        }
    }
}

int main(int argc, char** argv) {
    parse_args(argc, argv);

    LinkedList list = LinkedList();

    std::ifstream input(fileToComp);
    std::string line;

    while (std::getline(input, line)) {
        for (std::size_t i = 0; i < line.length(); ++i) {
            char currentChar = line[i];

            // verifica se ja existe esse caracter
            Cell* foundCell = list.getCellByChar(currentChar);

            if (foundCell == nullptr) {
                // nao existe o caracter. cria um novo e salva
                NodeItem newItem = NodeItem();
                newItem.setData(currentChar);
                newItem.setFrequency(1);

                list.insertEnd(newItem);
            } else {
                // caraceter ja existe na lista.
                NodeItem currentItem = foundCell->getItem();
                currentItem.setFrequency(currentItem.getFrequency() + 1);
                
                foundCell->setItem(currentItem);
            }
        }
    }

    list.print();
    debug(list.getSize());

    return 0;
}