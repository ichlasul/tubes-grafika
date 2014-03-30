#include "src/header/Point.hpp"

#include "src/header/Grafika.hpp"

int Point::getX() {
	return x;
}

int Point::getY() {
	return y;
}

bool Point::isOutOfBound() {
	return x >= 0 && x < Grafika::getMaxX() && y >= 0 && y < Grafika::getMaxY();
}

Point Point::up() {
	return Point(x, y - 1);
}

Point Point::down() {
	return Point(x, y + 1);
}

Point Point::left() {
	return Point(x - 1, y);
}

Point Point::right() {
	return Point(x + 1, y);
}