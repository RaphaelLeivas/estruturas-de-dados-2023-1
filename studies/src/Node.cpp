#include "../include/Node.hpp"

Node::Node() {
    NodeItem newItem = NodeItem();
    newItem.setFrequency(-1);

    this->item = newItem;   

    this->left = nullptr;
    this->right = nullptr;
}

void Node::setItem(NodeItem item) {
    this->item = item;
}

NodeItem Node::getItem() {
    return this->item;
}