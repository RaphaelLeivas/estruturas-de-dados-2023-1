#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include <stdexcept>

#include "Line.hpp"

#define debug(a) std::cout << a << std::endl

struct Node {
    Line value;
    struct Node *next;
    Node() = default;
};

class LinkedList {
   public:
    LinkedList();
    ~LinkedList();
    void printList();
    void insertEnd(Line);
    void insertStart(Line);
    Line getEnd();
    Line getStart();
    Line getByIndex(int);
    Line removeEnd();
    bool isEmpty();
    int getSize();

   private:
    Node *head;
    Node *tail;
    int size;
};

#endif