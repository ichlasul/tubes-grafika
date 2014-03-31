#include "src/header/Rock.hpp"

#include <conio.h>

Rock::Rock() {

}

Rock::Rock(Point p) {
	center = p;

	calculateAB();

	lineColor = DARKGRAY;
	fillColor = DARKGRAY;
}

Rock::~Rock() {
	
}

void Rock::calculateAB() {
	a = b = (center.getY() - 50 ) / 10;
}

void Rock::moveCloser(){
	center.moveRel(pos,3);
	calculateAB();

}
bool Rock::isCollision(Car car){
	bool output = false;
	int leftcar = car.getPosX() - (car.getLebar()/2);
	int rightcar = car.getPosX() + (car.getLebar()/2);
	int topcar = car.getPosY() - (car.getPanjang()/2);
	int bottomcar = car.getPosY() + (car.getPanjang()/2);

	int leftrock = center.getX() - a;
	int rightrock = center.getX() + a;
	int toprock = center.getY() - b;
	int bottomrock = center.getY() + b;

	if ((leftrock>=leftcar) && (leftrock<=rightcar) && (toprock>=topcar) && (toprock<=bottomcar)) {
		output = true;
	}

	if ((rightrock>=leftcar) && (rightrock<=rightcar) && (toprock>=topcar) && (toprock<=bottomcar)) {
		output = true;
	}

	if ((leftrock>=leftcar) && (leftrock<=rightcar) && (bottomrock>=topcar) && (bottomrock<=bottomcar)) {
		output = true;
	}

	if ((rightrock>=leftcar) && (rightrock<=rightcar) && (bottomrock>=topcar) && (bottomrock<=bottomcar)) {
		output = true;
	}

	return output;
}
void Rock::roll(){
	
}

void Rock::setPos(int x) {
	pos = x;
}