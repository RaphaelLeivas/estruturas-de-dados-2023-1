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
#include "../include/Utils.hpp"

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

void assignHuffmanCodes(Cell* root, std::string str) {
    if (!root) {
        return;
    }

    if (root->getItem().getData() != 0) {
        NodeItem item = root->getItem();
        item.setCode(str);
        root->setItem(item);
    }

    assignHuffmanCodes(root->left, str + "0");
    assignHuffmanCodes(root->right, str + "1");
}

int main(int argc, char** argv) {
    parse_args(argc, argv);

    Utils utils = Utils();
    LinkedList list = LinkedList();

    std::ifstream input(fileToComp);
    std::string line;

    int maxFreq = 0;  // usado na ordenação via counting sort

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

    // ordena a lista com counting sort
    utils.sortbyCountingSort(&list, maxFreq);

    while (list.getSize() != 1) {
        Cell* left = list.removeEndCell();
        Cell* right = list.removeEndCell();

        Cell* newCell = new Cell();
        newCell->left = left;
        newCell->right = right;

        NodeItem newItem = NodeItem();
        int newFreq =
            left->getItem().getFrequency() + right->getItem().getFrequency();
        newItem.setFrequency(newFreq);
        newCell->setItem(newItem);

        list.insertCellAtOrder(newCell);
    }

    // agora, a unica celula na lista encadeada é a raiz da arvore de Huffman.
    Cell* root = list.getFirstCell();

    // adiciona um codigo a cada membro da lista
    assignHuffmanCodes(root, "");

    list.printHuffmanCodes(root);

    return 0;
}