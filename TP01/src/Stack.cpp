#include "../include/Stack.hpp"

template <typename T> Stack<T>::Stack(int size) {
    this->size = size;
    this->top = -1;
    this->stack = new T[size];
}

template <typename T> Stack<T>::~Stack() { delete[] this->stack; }

template <typename T> void Stack<T>::setTop(int index) { this->top = index; }

template <typename T> void Stack<T>::push(T value) {
    if (this->isFull()) {
        throw std::invalid_argument("Unable to push to stack: Stack is full!");
    }

    this->setTop(top + 1);
    this->stack[top] = value;
}

template <typename T> T Stack<T>::pop() {
    if (this->isEmpty()) {
        throw std::invalid_argument(
            "Unable to pop from stack: Stack is empty!");
    }

    T result = this->stack[top];
    this->setTop(top - 1);

    return result;
}

template <typename T> bool Stack<T>::isEmpty() { return top == -1; }
template <typename T> bool Stack<T>::isFull() { return top == size - 1; }

template <typename T> void Stack<T>::print() {
    std::cout << "Top" << std::endl << "------" << std::endl;
    for (int i = top; i >= 0; --i) {
        std::cout << this->stack[i] << std::endl;
    }
    std::cout << "------" << std::endl << "Bottom" << std::endl;
}

// instancia explicitamente os templates que o codigo vai precisar
// assim fica mais limpo e modularizado entre .cpp e .hpp, pois nao precisa
// modificar as funções para deixar o template genérico

template class Stack<float>;
template class Stack<std::string>;
