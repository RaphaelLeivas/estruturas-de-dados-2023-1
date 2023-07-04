#include "../include/Cell.hpp"

Cell::Cell() {
    CellItem newItem = CellItem();
    newItem.setFrequency(-1);

    this->item = newItem;   
    this->next = nullptr;
}

void Cell::setItem(CellItem item) {
    this->item = item;
}

CellItem Cell::getItem() {
    return this->item;
}