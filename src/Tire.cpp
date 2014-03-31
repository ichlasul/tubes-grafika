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
	center.moveRel(0, 2);
	calculateAB();
}

bool Tire::isCollision(Car car){

}
void Tire::roll(){
	
}