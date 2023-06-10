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
