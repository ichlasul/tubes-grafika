#include "src/header/Tire.hpp"

#include <conio.h>

Tire::Tire() {

}

Tire::Tire(Point p) {
	center = p;

	a = (center.getY() - 50 ) / 8;
	b = (center.getY() - 50 ) / 12;

	lineColor = BLACK;
	fillColor = BLACK;
}

Tire::~Tire() {
	
}

void Tire::moveCloser(){

}
bool Tire::isCollision(Car car){

}
void Tire::roll(){
	
}