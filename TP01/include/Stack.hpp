#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <stdexcept>

class Stack {
   public:
    Stack(int size);
    ~Stack();
    float pop();
    void push(float value);
    bool isEmpty();
    bool isFull();

   private:
    int size;
    int top;
    float* stack;
    void setTop(int index);
};

#endif