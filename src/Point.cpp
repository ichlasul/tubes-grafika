#include "src/header/Point.hpp"

int Point::getX() {
	return x;
}

int Point::getY() {
	return y;
}

int Point::isOutOfBound() {
	return x >= 0 && x < 640 && y >= 0 && y < 480;
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