#ifndef CELL_ITEM_HPP
#define CELL_ITEM_HPP

#include <iostream>
#include <string>

class CellItem {
   public:
    CellItem();
    void setFrequency(int);
    void setData(char);
    int getFrequency();
    char getData();
    void print();
    void setCode(std::string);
    std::string getCode();

   private:
    int frequency;
    char data;
    int key;
    std::string code;
};

#endif
