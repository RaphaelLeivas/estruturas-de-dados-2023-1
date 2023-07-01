#include "../include/NodeItem.hpp"

NodeItem::NodeItem() { this->frequency = -1; }

void NodeItem::setFrequency(int freq) { this->frequency = freq; }

void NodeItem::setData(char data) { this->data = data; }

int NodeItem::getFrequency() { return this->frequency; }

char NodeItem::getData() { return this->data; }

void NodeItem::print() {
    std::cout << "Char = " << this->data << " Frequency: " << this->frequency
              << std::endl;
}