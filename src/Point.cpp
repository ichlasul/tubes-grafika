#include "Point.h"

int Point::getX() {
	return x;
}

int Point::getY() {
	return y;
}

bool Point::isOutOfBound() {
	return x >= 0 && x < 640 && y >= 0 && y < 480;
}

Point Point::up() {
	return new Point(x, y - 1);
}

Point Point::down() {
	return new Point(x, y + 1);
}

Point Point::left() {
	return new Point(x - 1, y);
}

Point Point::right() {
	return new Point(x + 1, y);
}