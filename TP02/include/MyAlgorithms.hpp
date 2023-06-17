#ifndef MY_ALGORITHMS_HPP
#define MY_ALGORITHMS_HPP

#include <math.h>
#include <time.h>

#include <iostream>
#include <stdexcept>

#include "Stack.hpp"
#include "List.hpp"

#define debug(a) std::cout << a << std::endl

enum class GrahamOption { INSERTION_SORT, MERGE_SORT, LINEAR_SORT };

class MyAlgorithms {
   public:
    MyAlgorithms();
    ~MyAlgorithms();
    List<Point>* getConvexPointsByJarvis(List<Point>*);
    List<Point>* getConvexPointsByGraham(List<Point>*, GrahamOption);

   private:
    // funcoes auxiliares
    int orientation(Point, Point, Point);
    double getDistanceBetween(Point, Point);
    void sortByAngleMergeSort(Point*, int, int);
    void sortByAngleInsertionSort(Point*, int);
    void sortByAngleCountingSort(Point*, int);
    void mergeHalves(Point*, int, int, int);
    Point getNextToTop(Stack<Point>&);
    List<Point>* checkSameAngles(Point*, int);
    Point getLargestPointAngle(Point*, int);
};

#endif
