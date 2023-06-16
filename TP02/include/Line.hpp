#ifndef LINE_HPP
#define LINE_HPP

#include <iostream>
#include <string>
#include <cmath>

#include "Point.hpp"

class Line {
   public:
    Line(Point, Point);
    Line(); // construtor padrao
    ~Line();
    void print();
    Point getStart();
    Point getEnd();
    std::string getEquation();

   private:
    Point start;
    Point end;
};

#endif