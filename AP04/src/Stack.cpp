#include "../include/Stack.hpp"

Stack::Stack(unsigned int size) {
    this->size = size;
    this->queue = new CircularQueue(size);
    this->auxQueue = new CircularQueue(size);
}

Stack::~Stack() {
    this->queue->empty();
    delete this->queue;
    delete this->auxQueue;
}

unsigned int Stack::getSize() { return this->size; }

void Stack::push(int value) {
    if (this->isFull()) {
        throw std::invalid_argument("Unable to push to stack: Stack is full!");
    }

    this->queue->add(value);
    std::cout << "Pushed to stack: " << value << std::endl;
}

int Stack::pop() {
    if (this->isEmpty()) {
        throw std::invalid_argument(
            "Unable to pop from stack: Stack is empty!");
    }

    int result = -1;

    // copia todos que estao na fila principal para a auxiliar ate chegar no
    // ultimo
    for (unsigned int i = 0; i < size; ++i) {
        result = this->queue->remove();
        if (!this->queue->isEmpty()) {
            this->auxQueue->add(result);
            continue;
        } else {
            break;
        }
    }

    // quando a fila principal esvaziar, result guarda a ultima posição
    // que é a resposta do Stack.pop()

    // agora volta tudo que esta na auxiliar de volta para a fila principal
    while (!this->auxQueue->isEmpty()) {
        this->queue->add(this->auxQueue->remove());
    }

    this->auxQueue->empty();

    std::cout << "Popped from stack: " << result << std::endl;

    return result;
}

bool Stack::isEmpty() { return this->queue->isEmpty(); }
bool Stack::isFull() { return this->queue->isFull(); }