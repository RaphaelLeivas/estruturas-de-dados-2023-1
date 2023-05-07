#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Node {
   public:
    Node();
    ~Node();
    int getItem();
    void setItem(int);
    void print();
    Node* left;
    Node* right;

   private:
    int item;
};

#endif