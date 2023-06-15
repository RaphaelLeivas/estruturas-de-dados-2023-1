#include "../include/ConvexHull.hpp"

ConvexHull::ConvexHull(int n) {
    this->n = n;
};

ConvexHull::~ConvexHull() {
    delete[] lines;
};

void ConvexHull::print() {
    this->lines->print();
};

void ConvexHull::addLine(Line line) {
    
}

// Point Line::getLines() {
//     return this->end;
// }