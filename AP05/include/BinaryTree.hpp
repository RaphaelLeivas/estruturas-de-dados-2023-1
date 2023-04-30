#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <iostream>
#include <stdexcept>
#include <string>

#include "Node.hpp"

enum class WALK_TYPES { PRE_ORDER, POST_ORDER, IN_ORDER, BY_LEVEL };

class BinaryTree {
   public:
    BinaryTree();
    ~BinaryTree();
    void insert(int);
    void walk(WALK_TYPES);
    void erase();

   private:
    Node* root;
    
    void insertRecursive(Node* &node, int item);
    void eraseRecursive(Node* node);
    void preOrder(Node* node);
    void postOrder(Node* node);
    void inOrder(Node* node);
    void byLevel();
};

#endif