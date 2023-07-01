#ifndef NODE_ITEM_HPP
#define NODE_ITEM_HPP

#include <iostream>
#include <string>

class NodeItem {
   public:
    NodeItem();
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
