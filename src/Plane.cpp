#include "src/header/Plane.hpp"
#include <graphics.h>

void Plane::floodFill(Point position) {
	if (getpixel(position.getX(), position.getY()) == lineColor) return;
	if (position.isOutOfBound()) return;

	putpixel(position.getX(), position.getY(), fillColor);
	floodFill(position.up());
	floodFill(position.right());
	floodFill(position.down());
	floodFill(position.left());
}