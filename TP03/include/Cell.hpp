#ifndef CELL_HPP
#define CELL_HPP

#include "NodeItem.hpp"

class Cell {
   public:
    Cell();
    void setItem(NodeItem);
    NodeItem getItem();

   private:
    NodeItem item;
    Cell* next;
    friend class LinkedList;
};

#endif
