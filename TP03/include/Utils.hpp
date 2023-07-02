#ifndef UTLS_HPP
#define UTLS_HPP

#include <iostream>
#include <string>
#include <bitset>
#include "LinkedList.hpp"

#define BYTE_IN_BITS 8

class Utils {
   public:
    Utils();
    ~Utils();
    void printArray(int*, int);
    void sortbyCountingSort(LinkedList* list, int max);
    std::bitset<BYTE_IN_BITS> charTo8Bits(char);
};

#endif