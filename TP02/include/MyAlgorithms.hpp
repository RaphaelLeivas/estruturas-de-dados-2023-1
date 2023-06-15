#ifndef MY_ALGORITHMS_HPP
#define MY_ALGORITHMS_HPP

#include <math.h>
#include <time.h>

#include <iostream>
#include <stdexcept>

#include "LinkedList.hpp"
#include "Stack.hpp"
#include "List.hpp"

#define debug(a) std::cout << a << std::endl

enum class GrahamOption { INSERTION_SORT, MERGE_SORT, RADIX_SORT };

class MyAlgorithms {
   public:
    MyAlgorithms();
    ~MyAlgorithms();
    void insertionSort(int*, int);
    void radixSort(int*, int);
    void mergeSort(int*, int, int);
    void printArray(int*, int);
    void fillArrayWithRandom(int*, int);
    List<Point>* getConvexHullByJarvis(List<Point>*);
    List<Point>* getConvexHullByGraham(List<Point>*);

   private:
    // funcoes auxiliares
    void merge(int*, int, int, int);
    void countingSort(int*, int, int);
    int getMaxInArray(int*, int);
    int orientation(Point, Point, Point);
    double getPolarAngle(Point, Point);
    double getDistanceBetween(Point, Point);
    void printPointsList(Point*, int);
    void sortByAngleMergeSort(Point*, int, int);
    void sortByAngleInsertionSort(Point*, int);
    void sortByAngleCountingSort(Point*, int);
    void mergeHalves(Point*, int, int, int);
    Point getNextToTop(Stack<Point>&);
    List<Point>* checkSameAngles(Point*, int);
    Point getLargestPoint(Point*, int);
};

#endif
