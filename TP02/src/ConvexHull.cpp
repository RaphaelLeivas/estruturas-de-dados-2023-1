#include "../include/ConvexHull.hpp"

ConvexHull::ConvexHull(List<Line>* lines) { this->lines = lines; };

ConvexHull::~ConvexHull() { delete lines; };

void ConvexHull::printPoints() {
    for (int i = 0; i < this->lines->getCurrentSize(); ++i) {
        Point startingPoint = this->lines->getByIndex(i).getStart();
        startingPoint.print();
    }
};

void ConvexHull::printLines() {
    for (int i = 0; i < this->lines->getCurrentSize(); ++i) {
        std::string equation = this->lines->getByIndex(i).getEquation();
        std::cout << equation << std::endl;
    }
}
