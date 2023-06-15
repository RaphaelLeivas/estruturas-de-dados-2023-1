#include <iostream>

#include "Line.hpp"
#include "List.hpp"

class ConvexHull {
   public:
    ConvexHull(int);
    ~ConvexHull();
    void print();
    void addLine(Line);
    Line* getLines();

   private:
    List<Line>* lines;
    int n;
};
