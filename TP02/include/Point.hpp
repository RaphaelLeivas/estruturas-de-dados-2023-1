#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

class Point {
   public:
    Point(int, int);
    Point(); // construtor padrao
    ~Point();
    void print();
    int getX();
    int getY();

   private:
    int x, y;
};

#endif
