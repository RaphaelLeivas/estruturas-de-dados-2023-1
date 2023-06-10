#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include <stdexcept>

#include "Point.hpp"

#define debug(a) std::cout << a << std::endl

struct Node {
    Point value;
    struct Node *next;
    Node() = default;
};

class LinkedList {
   public:
    LinkedList();
    ~LinkedList();
    void printList();
    void insertEnd(Point);
    void insertStart(Point);
    Point getEnd();
    Point getStart();
    Point getByIndex(int);
    Point removeEnd();
    bool isEmpty();
    int getSize();

   private:
    Node *head;
    Node *tail;
    int size;
};

#endif