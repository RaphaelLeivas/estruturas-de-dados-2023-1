#ifndef CELL_HPP
#define CELL_HPP

#include "CellItem.hpp"

class Cell {
   public:
    Cell();
    void setItem(CellItem);
    CellItem getItem();
    Cell* left;
    Cell* right;

   private:
    CellItem item;
    Cell* next;

    friend class LinkedList;
    friend class HuffmanTree;
};

#endif
