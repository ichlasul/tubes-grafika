#include "src/header/Point.hpp"

#include "src/header/Grafika.hpp"

Point::Point() : x(0), y(0){
}

Point::Point(int x, int y) : x(x), y(y){
}

Point::~Point(){
}

int Point::getX() {
	return x;
}

int Point::getY() {
	return y;
}

bool Point::isOutOfBound() {
	return x < 0 || x > Grafika::get_maxx() || y < 0 || y > Grafika::get_maxy();
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

void Point::moveRel(int dx, int dy) {
	x += dx;
	y += dy;
}