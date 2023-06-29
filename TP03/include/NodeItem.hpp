#ifndef NODE_ITEM_HPP
#define NODE_ITEM_HPP

#include <iostream>

class NodeItem {
   public:
    NodeItem();
    void setFrequency(int);
    void setData(char);
    int getFrequency();
    char getData();
    void print();

   private:
    int frequency;
    char data;
    int key;
};

#endif
