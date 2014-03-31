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
	center.moveRel(pos, 3);
	calculateVertices();
}

bool Box::isCollision(Car car){
	bool output = false;
	int leftcar = car.getPosX() - (car.getLebar()/2);
	int rightcar = car.getPosX() + (car.getLebar()/2);
	int topcar = car.getPosY() - (car.getPanjang()/2);
	int bottomcar = car.getPosY() + (car.getPanjang()/2);

	int leftObs = vertices[3].getX();
	int rightObs = vertices[4].getX();
	int topObs = vertices[0].getY();
	int bottomObs = vertices[3].getY();

	if ((leftObs>=leftcar) && (leftObs<=rightcar) && (topObs>=topcar) && (topObs<=bottomcar)) {
		output = true;
	}

	if ((rightObs>=leftcar) && (rightObs<=rightcar) && (topObs>=topcar) && (topObs<=bottomcar)) {
		output = true;
	}

	if ((leftObs>=leftcar) && (leftObs<=rightcar) && (bottomObs>=topcar) && (bottomObs<=bottomcar)) {
		output = true;
	}

	if ((rightObs>=leftcar) && (rightObs<=rightcar) && (bottomObs>=topcar) && (bottomObs<=bottomcar)) {
		output = true;
	}

	return output;
}

void Box::roll(){
	
}

void Box::setPos(int x) {
	pos = x;
}
