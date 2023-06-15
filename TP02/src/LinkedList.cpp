#include "../include/LinkedList.hpp"

LinkedList::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

LinkedList::~LinkedList() {
    if (this->head == nullptr) {
        return;
    }

    Node* p = this->head->next;
    while (p != nullptr) {
        this->head->next = p->next;
        delete p;
        p = this->head->next;
    };

    delete this->head;
}

void LinkedList::insertEnd(Point value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if (this->isEmpty()) {
        this->head = newNode;
        this->tail = newNode;
    } else {
        this->tail->next = newNode;
        this->tail = newNode;
    }

    this->size = this->size + 1;
}

void LinkedList::insertStart(Point value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if (this->isEmpty()) {
        this->head = newNode;
        this->tail = newNode;
    } else {
        newNode->next = this->head;
        this->head = newNode;
    }

    this->size = this->size + 1;
}

Point LinkedList::getStart() {
    if (!this->isEmpty()) {
        return this->head->value;
    } else {
        throw std::invalid_argument(
            "Unable to getStart from LinkedList: LinkedList is empty!");
    }
}

Point LinkedList::getEnd() {
    if (!this->isEmpty()) {
        return this->tail->value;
    } else {
        throw std::invalid_argument(
            "Unable to getEnd from LinkedList: LinkedList is empty!");
    }
}

Point LinkedList::getByIndex(int index) {
    if (this->isEmpty()) {
        throw std::invalid_argument(
            "Unable to getByIndex from LinkedList: LinkedList is empty!");
    }

    Node* current = this->head;
    for (int i = 0; i < this->size; ++i) {
        if (i == index) {
            return current->value;
        }

        current = current->next;
    }

    // se chegou ate aqui, index esta fora da lista
    throw std::invalid_argument(
        "Unable to getByIndex from LinkedList: index is outside the list!");
}

Point LinkedList::removeEnd() {
    if (this->isEmpty()) {
        throw std::invalid_argument(
            "Unable to removeEnd from LinkedList: LinkedList is empty!");
    }

    Point aux;

    // se so tem um elemento na lista, remove ele de uma vez
    if (head->next == nullptr) {
        aux = head->value;
        delete this->head;

        this->head = nullptr;
        this->tail = nullptr;

        this->size = this->size - 1;

        return aux;
    }

    Node* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }

    // agora current é o penultimo elemento da lista
    current->next = nullptr;
    aux = this->tail->value;
    delete this->tail;
    this->tail = current;

    this->size = this->size - 1;
    return aux;
}

void LinkedList::printList() {
    if (this->isEmpty()) {
        throw std::invalid_argument(
            "Unable to printList LinkedList: LinkedList is empty!");
    }

    Node* current = this->head;

    while (current != nullptr) {
        current->value.print();
        current = current->next;
    }
    std::cout << std::endl;
}

bool LinkedList::isEmpty() { return this->size == 0; }

int LinkedList::getSize() { return this->size; }
