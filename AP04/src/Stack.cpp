#include "../include/Stack.hpp"

Stack::Stack(unsigned int size) {
    this->size = size;
    this->queue = new CircularQueue(size);
}

Stack::~Stack() {}

void Stack::destroy() {
    this->queue->empty();
    delete this->queue;
}

unsigned int Stack::getSize() { return this->size; }

void Stack::push(int value) { this->queue->add(value); }

int Stack::pop() { return this->queue->remove(); }

bool Stack::isEmpty() { return this->getSize() == 0; }