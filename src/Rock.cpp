#include "src/header/Rock.hpp"

#include <conio.h>

Rock::Rock() {

}

Rock::Rock(Point p) {
	center = p;

	a = b = center.getY() / 12;

	lineColor = DARKGRAY;
	fillColor = BLACK;
}

Rock::~Rock() {
	
}

void Rock::moveCloser(){

}
bool Rock::isCollision(Car car){

}
void Rock::roll(){
	
}