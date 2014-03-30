#include "src/header/Box.hpp"

#include <conio.h>
#include <stdio.h>

Box::Box() {
	
}


Box::Box(int size) : size(size) {
	num = 6;
	center = Point(360, 200);

	vertices[0] = Point(center.getX() - size/3, center.getY() - size);
	vertices[1] = Point(center.getX() + size/3, center.getY() - size);
	vertices[2] = Point(center.getX() + size/2, center.getY() - size / 2);
	vertices[3] = Point(center.getX() + size/2, center.getY() + size / 2);
	vertices[4] = Point(center.getX() - size/2, center.getY() + size / 2);
	vertices[5] = Point(center.getX() - size/2, center.getY() - size / 2);

	lineColor = BLACK;
	fillColor = RED;
}

Box::~Box() {

}


