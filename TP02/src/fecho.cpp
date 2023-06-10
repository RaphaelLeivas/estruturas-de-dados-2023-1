#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include "../include/MyAlgorithms.hpp"

int main(int argc, char** argv) {
    MyAlgorithms* myAlgorithms = new MyAlgorithms();
    int N = 10;

    int* arr = new int[N];
    myAlgorithms->fillArrayWithRandom(arr, N);

    myAlgorithms->insertionSort(arr, N);

    myAlgorithms->printArray(arr, N);

    delete myAlgorithms;
    delete[] arr;

    return 0;
}
