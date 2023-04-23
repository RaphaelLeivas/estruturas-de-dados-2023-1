#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <stdexcept>

template <typename T> class Stack {
   public:
    Stack(int size);
    ~Stack();
    T pop();
    void push(T value);
    bool isEmpty();
    bool isFull();
    void print();

   private:
    int size;
    int top;
    T* stack;
    void setTop(int index);
};

#endif