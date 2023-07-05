#ifndef NODE_HPP
#define NODE_HPP

#include "NodeItem.hpp"

class Node {
   public:
    Node();
    void setItem(CellItem);
    CellItem getItem();

   private:
    CellItem item;

    Node* left;
    Node* right;
    friend class BinaryTree;
};

#endif
