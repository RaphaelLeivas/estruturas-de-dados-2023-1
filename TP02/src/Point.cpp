#include "../include/Point.hpp"

Point::Point(int x, int y) : x(x), y(y) {}

Point::Point() {};
Point::~Point() = default;

void Point::print() { std::cout << "(" << x << ", " << y << ")" << std::endl; }

int Point::getX() { return this->x; }
int Point::getY() { return this->y; }

void Point::setX(int x) { this->x = x; }
void Point::setY(int y) { this->y = y; }
