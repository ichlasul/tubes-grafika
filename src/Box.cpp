#include "src/header/Box.hpp"

#include <conio.h>

Box::Box() {
	
}


Box::Box(Point p) {
	num = 6;
	center = p;

	lineColor = BLACK;
	fillColor = RED;

	calculateVertices();
}

Box::~Box() {

}

void Box::calculateVertices() {
	size = (center.getY() - 50) / 6;

	vertices[0] = Point(center.getX() - size/3, center.getY() - size);
	vertices[1] = Point(center.getX() + size/3, center.getY() - size);
	vertices[2] = Point(center.getX() + size/2, center.getY() - size / 2);
	vertices[3] = Point(center.getX() + size/2, center.getY() + size / 2);
	vertices[4] = Point(center.getX() - size/2, center.getY() + size / 2);
	vertices[5] = Point(center.getX() - size/2, center.getY() - size / 2);
}

void Box::moveCloser(){
	center.moveRel(0, 3);
	calculateVertices();
}

bool Box::isCollision(Car car){

}
void Box::roll(){
	
}


