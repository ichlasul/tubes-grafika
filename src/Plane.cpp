#include "src/header/Plane.hpp"
#include <graphics.h>

void Plane::floodFill(Point position) {
	Grafika::floodFill(position, fillColor, lineColor);
}