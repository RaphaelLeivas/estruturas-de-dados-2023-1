#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "Cell.hpp"
#include <stdexcept>

#define debug(a) std::cout << a << std::endl

class LinkedList {
   public:
    LinkedList();
    ~LinkedList();
    int getSize();
    bool isEmpty();
    void clean();
    void print();
    NodeItem getItem(int);
    void setItem(NodeItem, int);

    // inserts
    void insertStart(NodeItem); // instaveis
    void insert(NodeItem, int); // instaveis
    void insertEnd(NodeItem);

    // getters

    // aux
    Cell* position(int, bool);

   private:
    Cell* head;
    Cell* tail;
    int size;
};

#endif