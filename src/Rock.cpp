#include "src/header/Rock.hpp"

#include <conio.h>

Rock::Rock() {

}

Rock::Rock(Point p) {
	center = p;

	a = b = (center.getY() - 50 ) / 10;

	lineColor = DARKGRAY;
	fillColor = DARKGRAY;
}

Rock::~Rock() {
	
}

void Rock::moveCloser(){

}
bool Rock::isCollision(Car car){

}
void Rock::roll(){
	
}