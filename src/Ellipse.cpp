#include "Ellipse.h"

Ellipse::Ellipse() {
	a = 0;
	b = 0;
	degree = 0;

	lineColor = 15;
	fillColor = 4;
	center = Point(0,0);
}

Ellipse::Ellipse(Point p, int a, int b) {
	a = 0;
	b = 0;
	degree = 0;
	lineColor = 15;
	fillColor = 4;
	center = p;
}

Ellipse::~Ellipse() {

}

void Ellipse::drawLine() {

}
void Ellipse::translate(int x, int y) {

}
void Ellipse::rotate(int theta) {

}
void Ellipse::scale(int width, int height) {

}