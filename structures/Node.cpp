#include "../include/Node.hpp"

Node::Node() {
    this->left = NULL;
    this->right = NULL;
}

Node::~Node() {}

int Node::getItem() {
    return this->item;
}

void Node::setItem(int item) {
    this->item = item;
}

void Node::print() {
    std::cout << this->item << std::endl;
}