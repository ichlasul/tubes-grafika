#include "src/header/Plane.hpp"

#include "src/header/Grafika.hpp"

void Plane::floodFill(Point position) {
	Grafika::flood_fill(position, fillColor, lineColor);
}