#include "../include/Line.hpp"

Line::Line(Point start, Point end) : start(start), end(end) {}

Line::Line(){};
Line::~Line() = default;

void Line::print() {
    std::cout << "Printing Line" << std::endl;
    this->start.print();
    this->end.print();
    std::cout << "------" << std::endl;
    std::cout << std::endl;
};

Point Line::getStart() { return this->start; }

Point Line::getEnd() { return this->end; }

std::string Line::getEquation() {
    int y1 = this->getStart().getY();
    int y2 = this->getEnd().getY();
    int x1 = this->getStart().getX();
    int x2 = this->getEnd().getX();

    if (x2 - x1 == 0) {
        // é uma reta vertical em x = x1 = x2
        return "x = " + std::to_string(x1);
    }
    
    double angularCoef =
        (y2 - y1) / (double)(x2 - x1);  // delta y sobre delta x

    double linearCoef = y1 - angularCoef * x1;

    int precisionVal = 3;
    std::string formattedAngularCoef =
        std::to_string(angularCoef)
            .substr(0,
                    std::to_string(angularCoef).find(".") + precisionVal + 1);
    std::string formattedLinearCoef =
        std::to_string(linearCoef > 0 ? linearCoef : (-1) * linearCoef)
            .substr(0, std::to_string(linearCoef).find(".") + precisionVal + 1);

    if (linearCoef < 0) {
        return "y = " + formattedAngularCoef + "x - " + formattedLinearCoef;
    } else if (linearCoef > 0) {
        return "y = " + formattedAngularCoef + "x + " + formattedLinearCoef;
    } else {  // linearCoef == 0
        return "y = " + formattedAngularCoef + "x";
    }
}
