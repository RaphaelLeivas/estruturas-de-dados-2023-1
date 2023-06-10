#include "../include/ConvexHull.hpp"

ConvexHull::ConvexHull() = default;

ConvexHull::~ConvexHull() = default;

void ConvexHull::print() {
    int numberOfLines = sizeof(Line) / sizeof(this->lines[0]);

    for (int i = 0; i < numberOfLines; ++i) {
        Line currentLine = this->lines[i];

        currentLine.print();
    }
};

// void ConvexHull::addLine(Line line) {
//     return this->start;
// }

// Point Line::getLines() {
//     return this->end;
// }