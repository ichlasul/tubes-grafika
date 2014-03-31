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

}
void Rock::roll(){
	
}

void Rock::setPos(int x) {
	pos = x;
}