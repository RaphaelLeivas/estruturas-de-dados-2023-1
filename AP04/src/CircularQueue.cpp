#include "../include/CircularQueue.hpp"


CircularQueue::CircularQueue(int size) {
    this->size = size;
    this->queuePointer = new int[this->size];
    this->front = -1;
    this->rear = -1;
}

CircularQueue::~CircularQueue() {
    delete[] this->queuePointer;
}

int CircularQueue::getSize() { return this->size; }
int CircularQueue::getRear() { return this->rear; }
int CircularQueue::getFront() { return this->front; }

void CircularQueue::setSize(int size) { this->size = size; }
void CircularQueue::setRear(int rear) { this->rear = rear; }
void CircularQueue::setFront(int front) { this->front = front; }

bool CircularQueue::isEmpty() {
    return front == -1;
}

bool CircularQueue::isFull() {
    return (front == 0 && rear == size - 1) || rear == (front - 1) % (size - 1);
}

void CircularQueue::add(int elem) {
    if (this->isFull()) {
        throw std::invalid_argument("Unable to add to queue: Queue is full!");
    } else if (front == -1) {
        this->setFront(0);
        this->setRear(0);
        this->queuePointer[rear] = elem;
    } else if (rear == size - 1 && front != 0) {
        rear = 0;
        this->queuePointer[rear] = elem;
    } else {
        this->setRear(rear + 1);
        this->queuePointer[rear] = elem;
    }
}

int CircularQueue::remove() {
    if (this->isEmpty()) {
        throw std::invalid_argument("Unable to remove from queue: Queue is empty!");
    }

    int data = this->queuePointer[front];
    this->queuePointer[front] = -1;

    if (front == rear) {
        this->setFront(-1);
        this->setRear(-1);
    } else if (front == size - 1)
        this->setFront(0);
    else
        this->setFront(front + 1);

    return data;
}

void CircularQueue::print() {
    for (int i = 0; i < size; ++i) {
        std::cout << "Queue index " << i << " = " << this->queuePointer[i] << std::endl;
    }
}

void CircularQueue::empty() {
    for (int i = 0; i < size; ++i) {
        this->queuePointer[i] = -1;
    }
}
