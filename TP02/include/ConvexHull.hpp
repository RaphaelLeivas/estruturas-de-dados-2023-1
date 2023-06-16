#include <iostream>

#include "Line.hpp"
#include "List.hpp"

class ConvexHull {
   public:
    ConvexHull(List<Line>*);
    ~ConvexHull();
    void printPoints();
    void printLines();
    // demais metodos de insert, remove, etc sao feitos via TAD List, ja
    // implementando

   private:
    List<Line>* lines;
};
