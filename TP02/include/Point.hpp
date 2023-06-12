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
    double getAngle();
    void setX(int);
    void setY(int);
    void setAngle(double);

   private:
    int x, y;
    double angle; // angulo polar, auxiliar para o Graham
};

#endif
