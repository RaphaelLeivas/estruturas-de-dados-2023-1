#include <stdio.h>
#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <string>

// file management
#include <getopt.h>

#include "../include/BinaryTree.hpp"
#include "../include/CircularQueue.hpp"

#define debug(a) std::cout << a << std::endl

void parse_args(int argc, char** argv) {
    int c;
    while ((c = getopt(argc, argv, "f:")) != EOF) {
    }
}

int main(int argc, char** argv) {
    // gera arvore aleatoria com 10 elementos inteiros
    BinaryTree* tree = new BinaryTree();
    tree->fillWithRandom();

    // extrai as filas dos caminhos percorridos
    CircularQueue<int>* preOrderQueue = tree->walk(WALK_TYPES::PRE_ORDER);
    CircularQueue<int>* postOrderQueue = tree->walk(WALK_TYPES::POST_ORDER);
    CircularQueue<int>* inOrderQueue = tree->walk(WALK_TYPES::IN_ORDER);

    delete tree;
    delete preOrderQueue;
    delete postOrderQueue;
    delete inOrderQueue;

    return 0;
}