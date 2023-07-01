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

void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << std::endl;
    }
}

int main(int argc, char** argv) {
    parse_args(argc, argv);

    LinkedList list = LinkedList();

    std::ifstream input(fileToComp);
    std::string line;

    int maxFreq = 0;  // usado na orndenação via counting sort

    while (std::getline(input, line)) {
        for (std::size_t i = 0; i < line.length(); ++i) {
            char currentChar = line[i];

            // verifica se ja existe esse caracter
            Cell* foundCell = list.getCellByChar(currentChar);
            int newFreq;

            if (foundCell == nullptr) {
                // nao existe o caracter. cria um novo e salva
                NodeItem newItem = NodeItem();
                newItem.setData(currentChar);
                newFreq = 1;
                newItem.setFrequency(newFreq);

                list.insertEnd(newItem);
            } else {
                // caraceter ja existe na lista.
                NodeItem currentItem = foundCell->getItem();
                newFreq = currentItem.getFrequency() + 1;
                currentItem.setFrequency(newFreq);

                foundCell->setItem(currentItem);
            }

            if (newFreq >= maxFreq) {
                maxFreq = newFreq;
            }
        }
    }

    list.print();

    // ordena a lista via countingsort
    int* count = new int[maxFreq + 1];
    int listSize = list.getSize();

    for (int i = 0; i < listSize; i++) {
        int num = list.getItem(i + 1).getFrequency();
        count[num]++;
    }

    for (int i = 1; i <= maxFreq; i++) {
        count[i] += count[i - 1];
    }

    LinkedList sortedList;

    for (int i = 0; i < listSize; i++) {
        NodeItem currentItem = list.getItem(i + 1);
        sortedList.insertEnd(currentItem);
    }

    for (int i = listSize - 1; i >= 0; i--) {
        NodeItem arrI = list.getItem(i + 1);
        sortedList.setItem(arrI, count[arrI.getFrequency()]);
        count[arrI.getFrequency()]--;
    }

    sortedList.print();

    delete[] count;

    return 0;
}