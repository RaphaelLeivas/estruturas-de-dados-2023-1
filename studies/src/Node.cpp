#include "../include/Node.hpp"

Node::Node() {
    CellItem newItem = CellItem();
    newItem.setFrequency(-1);

    this->item = newItem;   

    this->left = nullptr;
    this->right = nullptr;
}

void Node::setItem(CellItem item) {
    this->item = item;
}

CellItem Node::getItem() {
    return this->item;
}