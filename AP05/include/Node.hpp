#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Node {
   public:
    Node(T item);
    ~Node();

   private:
    T item;
    Node* left;
    Node* right;

    friend class BinaryTree;
};

#endif