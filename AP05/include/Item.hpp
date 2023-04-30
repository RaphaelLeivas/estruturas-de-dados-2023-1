#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>

template <typename T>
class Item {
   public:
    Item();
    Item(int key, T value);
    ~Item();
    T getValue();
    void setValue(T);
    void setKey(int);
    int getKey();
    void print();

   private:
    int key;
    T value;
};

#endif