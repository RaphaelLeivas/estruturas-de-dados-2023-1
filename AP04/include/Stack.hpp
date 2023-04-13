#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <stdexcept>
#include "CircularQueue.hpp"

class Stack {
   public:
    Stack(unsigned int size);
    ~Stack();
    int pop();
    void push(int value);
    bool isEmpty();
    void destroy();
    unsigned int getSize();

   private:
    unsigned int size;
    CircularQueue* queue;
};

#endif