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
    CellItem getItem(int);
    void setItem(CellItem, int);

    // inserts - nivel de item
    void insertStart(CellItem);
    void insert(CellItem, int);
    void insertEnd(CellItem);

    // inserts - nivel de celula
    void insertCellStart(Cell*);
    void insertCell(Cell*, int);
    void insertCellEnd(Cell*);

    // remove
    CellItem removeStart();
    CellItem remove(int);
    CellItem removeEnd();

    // aux
    Cell* position(int, bool);
    Cell* getCellByChar(char);
    Cell* removeEndCell(); // nao deleta a referencia da cell
    void insertEndCell(Cell*); 
    void insertCellAtOrder(Cell*); 
    Cell* getFirstCell();

   private:
    Cell* head;
    Cell* tail;
    int size;
};

#endif