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

    // inserts - nivel de item
    void insertStart(NodeItem);
    void insert(NodeItem, int);
    void insertEnd(NodeItem);

    // inserts - nivel de celula
    void insertCellStart(Cell*);
    void insertCell(Cell*, int);
    void insertCellEnd(Cell*);

    // remove
    NodeItem removeStart();
    NodeItem remove(int);
    NodeItem removeEnd();

    // aux
    Cell* position(int, bool);
    Cell* getCellByChar(char);
    Cell* removeEndCell(); // nao deleta a referencia da cell
    void insertEndCell(Cell*); 
    void insertCellAtOrder(Cell*); 
    Cell* getFirstCell();
    void printHuffmanCodes(Cell* root);

   private:
    Cell* head;
    Cell* tail;
    int size;
};

#endif