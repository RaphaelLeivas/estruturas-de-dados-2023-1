#ifndef CELL_HPP
#define CELL_HPP

#include "NodeItem.hpp"

class Cell {
   public:
    Cell();
    void setItem(NodeItem);
    NodeItem getItem();
    Cell* left;
    Cell* right;

   private:
    NodeItem item;
    Cell* next;

    friend class LinkedList;
};

#endif
