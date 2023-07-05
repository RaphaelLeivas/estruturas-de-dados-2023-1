#include "../include/CellItem.hpp"

CellItem::CellItem() {
    this->frequency = -1;
    this->data = 0;  // caracter ASCII nulo
    this->code = "";
}

void CellItem::setFrequency(int freq) { this->frequency = freq; }

void CellItem::setData(char data) { this->data = data; }

int CellItem::getFrequency() { return this->frequency; }

char CellItem::getData() { return this->data; }

std::string CellItem::getCode() { return this->code; }

void CellItem::setCode(std::string code) { this->code = code; }

void CellItem::print() {
    if (this->code != "") {
        std::cout << "Char = " << this->data
                  << " Frequency: " << this->frequency << " Code: " << this->code
                  << std::endl;
    } else {
        std::cout << "Char = " << this->data
                  << " Frequency: " << this->frequency << std::endl;
    }
}