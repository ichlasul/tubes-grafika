#include "src/header/Plane.hpp"

#include "src/header/Grafika.hpp"

void Plane::setCenter(Point point) {
	center = point;
}

void Plane::setLineColor(int color ) {
	lineColor = color;
}


void Plane::setFillColor(int color ) {
	fillColor = color;
}

void Plane::floodFill(Point position) {
	Grafika::flood_fill(position, fillColor, lineColor);
}