#include <stdio.h>
#include <stdlib.h>

#include <cctype>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>

// file management
#include <getopt.h>

#include "../include/BinaryTree.hpp"
#include "../include/CircularQueue.hpp"

#define debug(a) std::cout << a << std::endl
#define TREE_SIZE 10
#define debugArray(a) \
    for (int s = 0; s < TREE_SIZE; ++s) std::cout << a[s] << " "

void parse_args(int argc, char** argv) {
    int c;
    while ((c = getopt(argc, argv, "f:")) != EOF) {
    }
}

void initializeArray(int* arr) {
    for (int k = 0; k < TREE_SIZE; ++k) {
        arr[k] = -1;
    }
}

int getRandomInteger() {
    using u32 = uint_least32_t;
    using engine = std::mt19937;
    std::random_device os_seed;
    const u32 seed = os_seed();

    engine generator(seed);
    std::uniform_int_distribution<u32> distribute(0, 9);

    return distribute(generator);
}

bool ancestral(int i, int j, int* pre, int* post, int* in) {
    bool firstCondition = false, secondCondition = false,
         thridCondition = false;

    int i_index = -1, j_index = -1;

    // se o j esta a esquerda de i no posordem, j pode ser descendente de i
    for (int k = 0; k < TREE_SIZE; ++k) {
        if (post[k] == i) {
            i_index = k;
        }
        if (post[k] == j) {
            j_index = k;
        }
    }
    firstCondition = j_index < i_index;

    // se o j esta a direita de i no preordem, j pode ser descendente de i
    for (int k = 0; k < TREE_SIZE; ++k) {
        if (pre[k] == i) {
            i_index = k;
        }
        if (pre[k] == j) {
            j_index = k;
        }
    }
    secondCondition = j_index > i_index;

    int root = pre[0];  // raiz fica na primeira posicao no pre-ordem
    if (i == root) {
        // raiz é ancestral de todos
        return true;
    }

    // quebra o vetor de inordem em dois, um a esquerda da raiz e outro a
    // direita, e verifica se eles estao no memso lado
    int inorderLeft[TREE_SIZE];
    initializeArray(inorderLeft);
    int inorderRight[TREE_SIZE];
    initializeArray(inorderRight);

    for (int k = 0; k < TREE_SIZE; ++k) {
        if (in[k] != root) {
            // ainda nao chegou na raiz, joga para esquerda
            inorderLeft[k] = in[k];
        } else {
            // chegou na raiz: joga todo o resto para a direita
            for (int l = TREE_SIZE - 1; l > k; --l) {
                inorderRight[l] = in[l];
            }

            break;
        }
    }

    bool foundIleft = false, foundJleft = false;
    for (int k = 0; k < TREE_SIZE; ++k) {
        if (inorderLeft[k] == i) foundIleft = true;
        if (inorderLeft[k] == j) foundJleft = true;
    }

    bool foundIright = false, foundJright = false;
    for (int k = 0; k < TREE_SIZE; ++k) {
        if (inorderRight[k] == i) foundIright = true;
        if (inorderRight[k] == j) foundJright = true;
    }

    thridCondition = (foundIleft && foundJleft) || (foundIright && foundJright);

    // i é ancestral de j se as tres condicoes forem validas
    return firstCondition && secondCondition && thridCondition;
    // return thridCondition;
}

int main(int argc, char** argv) {
    // gera arvore aleatoria com 10 elementos inteiros
    BinaryTree* tree = new BinaryTree();
    tree->fillWithRandom(TREE_SIZE);

    // extrai as filas dos caminhos percorridos
    CircularQueue<int>* preOrderQueue = tree->walk(WALK_TYPES::PRE_ORDER);
    CircularQueue<int>* postOrderQueue = tree->walk(WALK_TYPES::POST_ORDER);
    CircularQueue<int>* inOrderQueue = tree->walk(WALK_TYPES::IN_ORDER);

    // converte as filas para vetores, para facilitar o uso
    int preOrder[TREE_SIZE];
    initializeArray(preOrder);
    int postOrder[TREE_SIZE];
    initializeArray(postOrder);
    int inOrder[TREE_SIZE];
    initializeArray(inOrder);

    int it = 0;
    while (!preOrderQueue->isEmpty()) {
        preOrder[it] = preOrderQueue->remove();
        ++it;
    }
    it = 0;
    while (!postOrderQueue->isEmpty()) {
        postOrder[it] = postOrderQueue->remove();
        ++it;
    }
    it = 0;
    while (!inOrderQueue->isEmpty()) {
        inOrder[it] = inOrderQueue->remove();
        ++it;
    }

    for (int k = 0; k < TREE_SIZE; k++) {
        int i = 0;
        int j = 0;

        while (i == j) {
            i = getRandomInteger();
            j = getRandomInteger();
        }

        std::cout << "Testando ancestral: "
                  << "(" << i << ", " << j << ")";
        if (ancestral(i, j, preOrder, postOrder, inOrder)) {
            std::cout << " SIM";
        } else {
            std::cout << " NAO";
        };

        std::cout << std::endl;
    }

    delete tree;
    delete preOrderQueue;
    delete postOrderQueue;
    delete inOrderQueue;

    return 0;
}