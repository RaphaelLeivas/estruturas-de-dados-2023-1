#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <stdexcept>

#include "Point.hpp"

template <typename T> class List {
   public:
    List(int);
    ~List();
    T getByIndex(int);
    T removeByIndex(int);
    void setAtIndex(T, int);
    void insertAtIndex(T, int);
    bool isEmpty();
    bool isFull();
    int getSize();
    int getCurrentSize();

   private:
    int size;
    int currentSize;
    T* list;
};

#endif