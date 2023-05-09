#ifndef CIRCULAR_QUEUE_HPP
#define CIRCULAR_QUEUE_HPP

#include <iostream>
#include <stdexcept>

template <typename T> class CircularQueue {
   public:
    CircularQueue(int);
    ~CircularQueue();

    void add(T);
    T remove();
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
    T* queue;

    // setters
    void setSize(int);
    void setRear(int);
    void setFront(int);
};

#endif