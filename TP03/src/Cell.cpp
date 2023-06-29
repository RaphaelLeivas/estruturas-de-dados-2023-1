#include "../include/Cell.hpp"

Cell::Cell() {
    NodeItem newItem = NodeItem();
    newItem.setFrequency(-1);

    this->item = newItem;   
    this->next = nullptr;
}

void Cell::setItem(NodeItem item) {
    this->item = item;
}

NodeItem Cell::getItem() {
    return this->item;
}