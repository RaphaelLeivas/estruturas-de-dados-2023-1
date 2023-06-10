#include <iostream>

#include "Line.hpp"

class ConvexHull {
   public:
    ConvexHull();
    ~ConvexHull();
    void print();
    void addLine(Line);
    Line* getLines();

   private:
    Line* lines; // array de Lines
};
