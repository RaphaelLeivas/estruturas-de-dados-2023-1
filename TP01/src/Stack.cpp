#include "../include/Stack.hpp"

Stack::Stack(int size) {
    this->size = size;
    this->top = -1;
    this->stack = new float[size];
}

Stack::~Stack() { delete[] this->stack; }

void Stack::setTop(int index) { this->top = index; }

void Stack::push(float value) {
    if (this->isFull()) {
        throw std::invalid_argument("Unable to push to stack: Stack is full!");
    }

    this->setTop(top + 1);
    this->stack[top] = value;
}

float Stack::pop() {
    if (this->isEmpty()) {
        throw std::invalid_argument(
            "Unable to pop from stack: Stack is empty!");
    }

    float result = this->stack[top];
    this->setTop(top - 1);

    return result;
}

bool Stack::isEmpty() { return top == -1; }
bool Stack::isFull() { return top == size - 1; }

void Stack::print() {
    std::cout << "Top" << std::endl << "------" << std::endl;
    for (int i = top; i >= 0; --i) {
        std::cout << this->stack[i] << std::endl;
    }
    std::cout << "------" << std::endl << "Bottom" << std::endl;
}
