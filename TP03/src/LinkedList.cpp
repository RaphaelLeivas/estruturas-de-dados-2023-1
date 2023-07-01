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
        throw std::invalid_argument(
            "LinkedList Error: unable to getItem in null cell");
    }

    return p->getItem();
}

NodeItem LinkedList::getItemByChar(char c) {
    Cell* p = this->head->next;

    while (p != nullptr) {
        NodeItem currentItem = p->getItem();

        if (currentItem.getData() == c) {
            return currentItem;
        }

        p = p->next;
    }

    return NodeItem();
}

void LinkedList::setItemByChar(NodeItem item) {
    Cell* p = this->head->next;

    while (p != nullptr) {
        NodeItem currentItem = p->getItem();

        if (currentItem.getData() == item.getData()) {
            p->setItem(item);
            return;
        }

        p = p->next;
    }
}

void LinkedList::setItem(NodeItem item, int pos) {
    Cell* p = this->position(pos, false);
    p->setItem(item);
}

void LinkedList::insertStart(NodeItem item) {
    Cell* newCell = new Cell();
    newCell->setItem(item);

    newCell->next = this->head->next;
    this->head->next = newCell;
    this->size = this->size + 1;

    if (newCell->next == nullptr) {
        this->tail = newCell;
    }
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
    Cell* p = this->position(pos, false);

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

NodeItem LinkedList::removeStart() {
    NodeItem aux;

    if (this->isEmpty()) {
        throw std::invalid_argument(
            "LinkedList Error: unable to remove from empty list");
    }

    Cell* p = this->head->next;
    this->head->next = p->next;
    this->size = this->size - 1;

    if (this->head->next == nullptr) {
        this->tail = this->head;
    }

    aux = p->getItem();

    delete p;
    return aux;
}

NodeItem LinkedList::removeEnd() {
    NodeItem aux;

    if (this->isEmpty()) {
        throw std::invalid_argument(
            "LinkedList Error: unable to remove from empty list");
    }

    Cell* p = this->position(this->size, true);
    p->next = nullptr;
    this->size = this->size - 1;

    aux = this->tail->getItem();
    delete this->tail;
    this->tail = p;

    return aux;
}

NodeItem LinkedList::remove(int pos) {
    NodeItem aux;

    if (this->isEmpty()) {
        throw std::invalid_argument(
            "LinkedList Error: unable to remove from empty list");
    }

    Cell* p = this->position(pos, true);
    Cell* q = p->next;

    p->next = q->next;
    this->size = this->size - 1;
    aux = q->getItem();

    delete q;

    if (p->next == nullptr) {
        this->tail = p;
    }

    return aux;
}

// auxiliar
Cell* LinkedList::position(int pos, bool before = false) {
    // OBS: pos varia de 1 ate size, nao comeca em zero
    if (pos > this->size || pos <= 0) {
        debug(pos);
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
