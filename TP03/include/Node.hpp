#ifndef NODE_HPP
#define NODE_HPP

#include "NodeItem.hpp"

class Node {
   public:
    Node();
    void setItem(NodeItem);
    NodeItem getItem();

   private:
    NodeItem item;

    Node* left;
    Node* right;
    friend class BinaryTree;
};

#endif
