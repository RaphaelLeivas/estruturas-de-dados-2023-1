#include "../include/CircularQueue.hpp"

template <typename T>
CircularQueue<T>::CircularQueue(int size) {
    this->size = size;
    this->queue = new T[this->size];
    this->front = -1;
    this->rear = -1;
}

template <typename T>
CircularQueue<T>::~CircularQueue() {
    delete[] this->queue;
}

template <typename T>
int CircularQueue<T>::getSize() { return this->size; }
template <typename T>
int CircularQueue<T>::getRear() { return this->rear; }
template <typename T>
int CircularQueue<T>::getFront() { return this->front; }

template <typename T>
void CircularQueue<T>::setSize(int size) { this->size = size; }
template <typename T>
void CircularQueue<T>::setRear(int rear) { this->rear = rear; }
template <typename T>
void CircularQueue<T>::setFront(int front) { this->front = front; }

template <typename T>
bool CircularQueue<T>::isEmpty() {
    return front == -1;
}

template <typename T>
bool CircularQueue<T>::isFull() {
    return (front == 0 && rear == size - 1) || rear == (front - 1) % (size - 1);
}

template <typename T>
void CircularQueue<T>::add(T elem) {
    if (this->isFull()) {
        throw std::invalid_argument("Unable to add to queue: Queue is full!");
    } else if (front == -1) {
        this->setFront(0);
        this->setRear(0);
        this->queue[rear] = elem;
    } else if (rear == size - 1 && front != 0) {
        rear = 0;
        this->queue[rear] = elem;
    } else {
        this->setRear(rear + 1);
        this->queue[rear] = elem;
    }
}

template <typename T>
T CircularQueue<T>::remove() {
    if (this->isEmpty()) {
        throw std::invalid_argument("Unable to remove from queue: Queue is empty!");
    }

    T data = this->queue[front];
    this->queue[front] = T();

    if (front == rear) {
        this->setFront(-1);
        this->setRear(-1);
    } else if (front == size - 1)
        this->setFront(0);
    else
        this->setFront(front + 1);

    return data;
}

template <typename T>
void CircularQueue<T>::print() {
    for (int i = 0; i < size; ++i) {
        std::cout << "Queue index " << i << " = " << this->queue[i] << std::endl;
    }
}

template <typename T>
void CircularQueue<T>::empty() {
    for (int i = 0; i < size; ++i) {
        this->queue[i] = T();
    }
}

template class CircularQueue<int>;
template class CircularQueue<char>;
template class CircularQueue<std::string>;
