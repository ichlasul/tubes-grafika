#include "src/header/Box.hpp"

#include <conio.h>
#include <stdio.h>

Box::Box() {
	
}


Box::Box(Point p) {
	num = 6;
	center = p;

	lineColor = BLACK;
	fillColor = RED;

	size = (center.getY() / 8);

	calculateVertices();
}

Box::~Box() {

}

void Box::calculateVertices() {
	vertices[0] = Point(center.getX() - size/3, center.getY() - size);
	vertices[1] = Point(center.getX() + size/3, center.getY() - size);
	vertices[2] = Point(center.getX() + size/2, center.getY() - size / 2);
	vertices[3] = Point(center.getX() + size/2, center.getY() + size / 2);
	vertices[4] = Point(center.getX() - size/2, center.getY() + size / 2);
	vertices[5] = Point(center.getX() - size/2, center.getY() - size / 2);
}

void Box::moveCloser(){
	center.moveRel(0, 5);
	calculateVertices();
}

bool Box::isCollision(Car car){

}
void Box::roll(){
	
}


