#ifndef CIRCULAR_QUEUE_HPP
#define CIRCULAR_QUEUE_HPP

#include <iostream>
#include <stdexcept>
#include <fstream>

class CircularQueue {
   public:
    CircularQueue(int);
    ~CircularQueue();

    void add(int);
    int remove();
    void print();
    void empty();
    bool isEmpty();
    bool isFull();

    // getters
    int getSize();
    int getRear();
    int getFront();

   private:
    int size;
    int front, rear;
    int* queue;

    // setters
    void setSize(int);
    void setRear(int);
    void setFront(int);
};

#endif