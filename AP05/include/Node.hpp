#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <stdexcept>
#include <string>

#include "Item.hpp"

template <typename T>
class Node {
   public:
    Node();
    ~Node();
    Item<T>* getItem();

   private:
    Item<T>* item;
    Node* left;
    Node* right;

    friend class BinaryTree;
};

#endif