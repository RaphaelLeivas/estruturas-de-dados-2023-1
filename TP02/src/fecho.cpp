#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include "../include/MyAlgorithms.hpp"
#include "../include/Point.hpp"
#include "../include/Line.hpp"

int main(int argc, char** argv) {
    Point* p1 = new Point(0, 0);
    Point* p2 = new Point(10, 5);

    Line* l1 = new Line(*p1, *p2);

    l1->print();

    delete l1;
    delete p1;
    delete p2;

    return 0;

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
