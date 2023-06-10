#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include "../include/MyAlgorithms.hpp"

int main(int argc, char** argv) {
    MyAlgorithms* myAlgorithms = new MyAlgorithms();

    int num = 100;
    int N = 12;

    int* arr = new int[N];
    myAlgorithms->fillArrayWithRandom(arr, N);

    std::cout << num << std::endl;

    myAlgorithms->mergeSort(arr, 0, N - 1);

    myAlgorithms->printArray(arr, N);

    delete myAlgorithms;
    delete[] arr;

    return 0;
}
