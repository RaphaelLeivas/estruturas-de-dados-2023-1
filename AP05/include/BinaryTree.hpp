#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <iostream>
#include <stdexcept>
#include <string>

#include "Node.hpp"
#include "CircularQueue.hpp"

#define AUX_QUEUE_SIZE 10

enum class WALK_TYPES { PRE_ORDER, POST_ORDER, IN_ORDER, BY_LEVEL };

class BinaryTree {
   public:
    BinaryTree();
    ~BinaryTree();
    void insert(int);
    CircularQueue<int>* walk(WALK_TYPES);
    void erase();
    void fillWithRandom(int n);

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