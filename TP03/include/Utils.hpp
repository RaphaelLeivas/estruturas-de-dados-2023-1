#ifndef UTLS_HPP
#define UTLS_HPP

#include <iostream>
#include <string>
#include "LinkedList.hpp"

class Utils {
   public:
    Utils();
    ~Utils();
    void printArray(int*, int);
    void sortbyCountingSort(LinkedList* list, int max);
};

#endif