#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <iostream>
#include <stdexcept>
#include <string>

#include "Item.hpp"
#include "Node.hpp"

enum class WALK_TYPES { PRE_ORDER, POST_ORDER, IN_ORDER, BY_LEVEL };

template <typename T>
class BinaryTree {
   public:
    BinaryTree();
    ~BinaryTree();
    void insert(Item<T>);
    void walk(WALK_TYPES);
    void erase();

   private:
    Node<T>* root;
    
    void insertRecursive(Node<T>* node, Item<T> item);
    void eraseRecursive(Node<T>* node);
    void preOrder(Node<T>* node);
    void postOrder(Node<T>* node);
    void inOrder(Node<T>* node);
    void byLevel();
};

#endif