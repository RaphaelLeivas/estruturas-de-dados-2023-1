#include <iostream>
#include <time.h>

#define debug(a) std::cout << a << std::endl

class MyAlgorithms {
    public:
        MyAlgorithms(); 
        ~MyAlgorithms();
        void insertionSort(int*, int);
        void mergeSort(int*, int, int);
        void printArray(int*, int);
        void fillArrayWithRandom(int*, int);

    private:
        // funcoes auxiliares
        void merge(int*, int, int, int);
};
