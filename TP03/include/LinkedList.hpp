#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "Cell.hpp"
#include <stdexcept>
#include <string>

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
    void insertStart(NodeItem);
    void insert(NodeItem, int);
    void insertEnd(NodeItem);

    // remove
    NodeItem removeStart();
    NodeItem remove(int);
    NodeItem removeEnd();

    // aux
    Cell* position(int, bool);
    Cell* getCellByChar(char);

   private:
    Cell* head;
    Cell* tail;
    int size;
};

#endif