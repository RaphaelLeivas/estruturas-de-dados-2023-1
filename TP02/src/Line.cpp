#include "../include/Line.hpp"

Line::Line(Point start, Point end) : start(start), end(end) {}

Line::Line() {};
Line::~Line() = default;

void Line::print() {
    std::cout << "Printing Line" << std::endl;
    this->start.print();
    this->end.print();
    std::cout << "------" << std::endl;
    std::cout << std::endl;
};

Point Line::getStart() {
    return this->start;
}

Point Line::getEnd() {
    return this->end;
}

std::string Line::getEquation() {
    int y1 = this->getStart().getY();
    int y2 = this->getEnd().getY();
    int x1 = this->getStart().getX();
    int x2 = this->getEnd().getX();

    double angularCoef = (y2 - y1) / (double)(x2 - x1); // delta y sobre delta x
    double linearCoef = y1 - angularCoef * x1;

    if (linearCoef < 0) {
        return "y = " + std::to_string(angularCoef) + " * x - " + std::to_string(linearCoef * -1);
    } else if (linearCoef > 0) {
        return "y = " + std::to_string(angularCoef) + " * x + " + std::to_string(linearCoef);
    } else { // linearCoef == 0
        return "y = " + std::to_string(angularCoef) + " * x";
    }
}

