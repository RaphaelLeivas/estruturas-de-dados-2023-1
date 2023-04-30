#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <cctype>
#include <random>

#include "Node.hpp"
#include "CircularQueue.hpp"

#define RANDOM_TREE_SIZE 10

enum class WALK_TYPES { PRE_ORDER, POST_ORDER, IN_ORDER, BY_LEVEL };

class BinaryTree {
   public:
    BinaryTree();
    ~BinaryTree();
    void insert(int);
    CircularQueue<int>* walk(WALK_TYPES);
    void erase();
    void fillWithRandom();

   private:
    Node* root;
    
    void insertRecursive(Node* &node, int item);
    void eraseRecursive(Node* node);
    void preOrder(Node* node, CircularQueue<int>* &q);
    void postOrder(Node* node, CircularQueue<int>*& q);
    void inOrder(Node* node, CircularQueue<int>*& q);
    void byLevel();
};

#endif