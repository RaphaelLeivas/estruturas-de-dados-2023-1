#ifndef MY_ALGORITHMS_HPP
#define MY_ALGORITHMS_HPP

#include <iostream>
#include <time.h>
#include <stdexcept>

#include "LinkedList.hpp"

#define debug(a) std::cout << a << std::endl

class MyAlgorithms {
    public:
        MyAlgorithms(); 
        ~MyAlgorithms();
        void insertionSort(int*, int);
        void radixSort(int*, int);
        void mergeSort(int*, int, int);
        void printArray(int*, int);
        void fillArrayWithRandom(int*, int);
        LinkedList getConvexHullByJarvis(LinkedList);

    private:
        // funcoes auxiliares
        void merge(int*, int, int, int);
        void countingSort(int*, int, int);
        int getMaxInArray(int*, int);
        int orientation(Point, Point, Point);
};

#endif
