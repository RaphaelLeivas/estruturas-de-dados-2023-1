#include "../include/LinkedList.hpp"

LinkedList::LinkedList() {
    this->size = 0;
    this->head = new Cell();
    this->tail = head;
}

LinkedList::~LinkedList() {
    this->clean();

    if (this->head != nullptr) {
        delete this->head;
    }
}

int LinkedList::getSize() { return this->size; }

bool LinkedList::isEmpty() { return this->size == 0; }

CellItem LinkedList::getItem(int pos) {
    Cell* p = this->position(pos, false);

    if (p == nullptr) {
        throw std::invalid_argument(
            "LinkedList Error: unable to getItem in null cell");
    }

    return p->getItem();
}

Cell* LinkedList::getCellByChar(char c) {
    Cell* p = this->head->next;

    while (p != nullptr) {
        CellItem currentItem = p->getItem();

        if (currentItem.getData() == c) {
            return p;
        }

        p = p->next;
    }

    return nullptr;
}

void LinkedList::setItem(CellItem item, int pos) {
    Cell* p = this->position(pos, false);
    p->setItem(item);
}

void LinkedList::insertStart(CellItem item) {
    Cell* newCell = new Cell();
    newCell->setItem(item);

    newCell->next = this->head->next;
    this->head->next = newCell;
    this->size = this->size + 1;

    if (newCell->next == nullptr) {
        this->tail = newCell;
    }
}

void LinkedList::insertCellStart(Cell* cell) {
    cell->next = this->head->next;
    this->head->next = cell;
    this->size = this->size + 1;

    if (cell->next == nullptr) {
        this->tail = cell;
    }
}

void LinkedList::insertEnd(CellItem item) {
    Cell* newCell = new Cell();

    newCell->setItem(item);

    this->tail->next = newCell;
    this->tail = newCell;

    this->size = this->size + 1;
}

void LinkedList::insertCellEnd(Cell* cell) {
    this->tail->next = cell;
    this->tail = cell;

    this->size = this->size + 1;
}

void LinkedList::insert(CellItem item, int pos) {
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

void LinkedList::insertCell(Cell* cell, int pos) {
    Cell* p = this->position(pos, false);

    cell->next = p->next;
    p->next = cell;

    if (cell->next == nullptr) {
        this->tail = cell;
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

CellItem LinkedList::removeStart() {
    CellItem aux;

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

CellItem LinkedList::removeEnd() {
    CellItem aux;

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

CellItem LinkedList::remove(int pos) {
    CellItem aux;

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
        throw std::invalid_argument("LinkedList Error: invalid position: " +
                                    std::to_string(pos));
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

Cell* LinkedList::removeEndCell() {
    if (this->isEmpty()) {
        throw std::invalid_argument(
            "LinkedList Error: unable to remove from empty list");
    }

    Cell* aux = this->tail;

    Cell* p = this->position(this->size, true);
    p->next = nullptr;
    this->size = this->size - 1;

    this->tail = p;

    return aux;
}

void LinkedList::insertEndCell(Cell* cell) {
    this->tail->next = cell;
    this->tail = cell;

    this->size = this->size + 1;
}

void LinkedList::insertCellAtOrder(Cell* cell) {
    Cell* p = this->head->next;
    int freq = cell->getItem().getFrequency();
    int position = 0;

    while (p != nullptr) {
        position++;
        int currentFreq = p->getItem().getFrequency();

        if (currentFreq < freq) {
            int positionToInsert = position - 1;

            if (positionToInsert == 0) {
                this->insertCellStart(cell);
            } else {
                this->insertCell(cell, position - 1);
            }

            return;
        }

        p = p->next;
    }

    // se chegou ate aqui, insere no final
    this->insertCellEnd(cell);
}

Cell* LinkedList::getFirstCell() { return this->head->next; }
