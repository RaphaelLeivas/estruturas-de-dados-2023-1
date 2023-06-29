#include "../include/LinkedList.hpp"

LinkedList::LinkedList() {
    this->size = 0;
    this->head = new Cell();
    this->tail = head;
}

LinkedList::~LinkedList() {
    this->clean();
    delete this->head;
}

int LinkedList::getSize() { return this->size; }

bool LinkedList::isEmpty() { return this->size == 0; }

NodeItem LinkedList::getItem(int pos) {
    Cell* p = this->position(pos, false);

    if (p == nullptr) {
        throw std::invalid_argument("LinkedList Error: unable to getItem in null cell");
    }

    return p->getItem();
}

void LinkedList::setItem(NodeItem item, int pos) {
    Cell* p = this->position(pos, false);
    p->setItem(item);
}

void LinkedList::insertStart(NodeItem item) {
    Cell* newCell = new Cell();
    newCell->setItem(item);

    newCell->next = this->head;

    if (this->head->next == nullptr) {
        this->tail = newCell;
    }

    this->head = newCell;
    this->size = this->size + 1;
}

void LinkedList::insertEnd(NodeItem item) {
    Cell* newCell = new Cell();

    newCell->setItem(item);

    this->tail->next = newCell;
    this->tail = newCell;

    this->size = this->size + 1;
}

void LinkedList::insert(NodeItem item, int pos) {
    Cell* newCell = new Cell();
    Cell* p = this->position(pos, true);

    newCell->setItem(item);

    newCell->next = p->next;
    p->next = newCell;

    if (newCell->next == nullptr) {
        this->tail = newCell;
    }

    this->size = this->size + 1;
}

void LinkedList::clean() {
    Cell* p = this->head->next;

    while (p != nullptr) {
        this->head->next = p->next;
        delete p;
        p = this->head->next;
    }

    this->tail = this->head;
    this->size = 0;
}

void LinkedList::print() {
    Cell* p = this->head->next;

    std::cout << "STARTING LIST PRINT" << std::endl;
    std::cout << "-------------------" << std::endl;

    while (p != nullptr) {
        p->getItem().print();
        p = p->next;
    }

    std::cout << "-------------------" << std::endl;
    std::cout << "END LIST PRINT" << std::endl;
}

// auxiliar
Cell* LinkedList::position(int pos, bool before = false) {
    if (pos > this->size || pos < 0) {
        throw std::invalid_argument("LinkedList Error: invalid position");
    }

    Cell* p = this->head;

    for (int i = 1; i < pos; ++i) {
        p = p->next;
    }

    if (!before) {
        p = p->next;
    }

    return p;
}
