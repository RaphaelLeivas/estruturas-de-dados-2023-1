#include "../include/NodeItem.hpp"

NodeItem::NodeItem() {
    this->frequency = -1;
    this->data = 0;  // caracter ASCII nulo
    this->code = "";
}

void NodeItem::setFrequency(int freq) { this->frequency = freq; }

void NodeItem::setData(char data) { this->data = data; }

int NodeItem::getFrequency() { return this->frequency; }

char NodeItem::getData() { return this->data; }

std::string NodeItem::getCode() { return this->code; }

void NodeItem::setCode(std::string code) { this->code = code; }

void NodeItem::print() {
    if (this->code != "") {
        std::cout << "Char = " << this->data
                  << " Frequency: " << this->frequency << " Code: " << this->code
                  << std::endl;
    } else {
        std::cout << "Char = " << this->data
                  << " Frequency: " << this->frequency << std::endl;
    }
}