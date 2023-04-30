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
    void setItem(Item<T>*);

   private:
    Item<T>* item;
    Node* left;
    Node* right;
};

#endif