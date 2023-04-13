#ifndef CIRCULAR_QUEUE_HPP
#define CIRCULAR_QUEUE_HPP

#include <iostream>
#include <stdexcept>

class CircularQueue {
   public:
    CircularQueue(int);
    ~CircularQueue();
    int getSize();
    int getRear();
    int getFront();
    void add(int);
    int remove();
    void print();
    void empty();
    bool isEmpty();
    bool isFull();

   private:
    int size;
    int front, rear;
    int* queuePointer;
    void setSize(int);
    void setRear(int);
    void setFront(int);
};

#endif