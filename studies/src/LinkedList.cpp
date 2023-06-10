#include "../include/LinkedList.hpp"

LinkedList::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}

LinkedList::~LinkedList() {
    Node* p = this->head->next;
    while (p != nullptr) {
        this->head->next = p->next;
        delete p;
        p = this->head->next;
    };

    delete this->head;
}

void LinkedList::insertEnd(int value) {
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
}

void LinkedList::insertStart(int value) {
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
}

int LinkedList::getStart() {
    if (!this->isEmpty()) {
        return this->head->value;
    } else {
        throw std::invalid_argument(
            "Unable to getStart from LinkedList: LinkedList is empty!");
    }
}

int LinkedList::getEnd() {
    if (!this->isEmpty()) {
        return this->tail->value;
    } else {
        throw std::invalid_argument(
            "Unable to getEnd from LinkedList: LinkedList is empty!");
    }
}

int LinkedList::removeStart() {
    if (this->isEmpty()) {
        throw std::invalid_argument(
            "Unable to removeStart from LinkedList: LinkedList is empty!");
    }

    int aux = this->head->value;
    Node* nextNode = this->head->next;
    delete this->head;
    this->head = nextNode;

    return aux;
}

int LinkedList::removeEnd() {
    if (this->isEmpty()) {
        throw std::invalid_argument(
            "Unable to removeEnd from LinkedList: LinkedList is empty!");
    }

    int aux;

    // se so tem um elemento na lista, remove ele de uma vez
    if (head->next == nullptr) {
        aux = head->value;
        
        delete this->head;

        this->head = nullptr;
        this->tail = nullptr;
        
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

    return aux;
}

void LinkedList::printList() {
    Node* current = this->head;

    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

bool LinkedList::isEmpty() {
    return (this->head == nullptr) && (this->tail == nullptr);
}
