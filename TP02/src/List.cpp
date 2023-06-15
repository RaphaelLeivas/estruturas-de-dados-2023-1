#include "../include/List.hpp"

template <typename T>
List<T>::List(int size) {
    this->size = size;
    this->currentSize = 0;
    this->list = new T[size];
}

template <typename T>
List<T>::~List() {
    delete[] this->list;
}

template <typename T>
T List<T>::getByIndex(int index) {
    if (this->isEmpty()) {
        throw std::invalid_argument("Unable to get from list: List is empty!");
    }

    if (index >= this->currentSize || index < 0) {
        throw std::invalid_argument(
            "Unable to get from list: invalid index provided.");
    }

    return this->list[index];
}

template <typename T>
void List<T>::setAtIndex(T value, int index) {
    if (index >= this->currentSize || index < 0) {
        throw std::invalid_argument(
            "Unable to set at list: invalid index provided.");
    }

    this->list[index] = value;
}

template <typename T>
void List<T>::insertAtIndex(T value, int index) {
    if (this->isFull()) {
        throw std::invalid_argument("Unable to insert at list: List is full!");
    }

    if (index > this->currentSize || index < 0) {
        throw std::invalid_argument(
            "Unable to insert at list: invalid index provided.");
    }

    this->currentSize++;

    for (int i = this->currentSize; i > index; --i) {
        this->list[i] = this->list[i - 1];
    }

    this->list[index] = value;
}

template <typename T>
T List<T>::removeByIndex(int index) {
    T aux;

    if (index >= this->currentSize || index < 0) {
        throw std::invalid_argument(
            "Unable to remove from list: invalid index provided.");
    }

    aux = this->list[index];

    for (int i = index; i < this->currentSize; ++i) {
        this->list[i] = this->list[i + 1];
    }

    this->currentSize--;

    return aux;
}

template <typename T>
bool List<T>::isEmpty() {
    return this->currentSize == 0;
}
template <typename T>
bool List<T>::isFull() {
    return this->currentSize == this->size;
}

template <typename T>
int List<T>::getSize() {
    return this->size;
}

template <typename T>
int List<T>::getCurrentSize() {
    return this->currentSize;
}

template class List<Point>;  // TP 02
template class List<int>;
