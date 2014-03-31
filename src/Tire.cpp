#include "src/header/Tire.hpp"

#include <conio.h>

Tire::Tire() {

}

Tire::Tire(Point p) {
	center = p;

	calculateAB();

	lineColor = BLACK;
	fillColor = BLACK;
}

Tire::~Tire() {
	
}

void Tire::calculateAB() {
	a = (center.getY() - 50 ) / 8;
	b = (center.getY() - 50 ) / 12;
}

void Tire::moveCloser(){
	center.moveRel(pos, 3);
	calculateAB();
}

bool Tire::isCollision(Car car){
bool output = false;
	int leftcar = car.getPosX() - (car.getLebar()/2);
	int rightcar = car.getPosX() + (car.getLebar()/2);
	int topcar = car.getPosY() - (car.getPanjang()/2);
	int bottomcar = car.getPosY() + (car.getPanjang()/2);

	int leftObs = center.getX() - a;
	int rightObs = center.getX() + a;
	int topObs = center.getY() - b;
	int bottomObs = center.getY() + b;

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
void Tire::roll(){
	
}

void Tire::setPos(int x) {
	pos = x;
}