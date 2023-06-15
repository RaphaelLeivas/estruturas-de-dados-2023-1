#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <stdexcept>

#include "Point.hpp"

template <typename T> class List {
   public:
    List(int);
    ~List();

    // getters
    T getByIndex(int);
    T getEnd();
    T getStart();

    // setters
    void setAtIndex(T, int);
    void setStart(T);
    void setEnd(T);

    // insert
    void insertAtIndex(T, int);
    void insertStart(T);
    void insertEnd(T);

    // remove
    T removeByIndex(int);
    T removeStart();
    T removeEnd();

    // aux
    bool isEmpty();
    bool isFull();
    int getSize();
    int getCurrentSize();

   private:
    int size;
    int currentSize;
    T* list = NULL;
};

#endif