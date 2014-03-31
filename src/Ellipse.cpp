#include "src/header/Ellipse.hpp"

#include "src/header/Grafika.hpp"

Ellipse::Ellipse() {
	a = 0;
	b = 0;
	degree = 0;

	lineColor = 15;
	fillColor = 4;
	center = Point(0,0);
}

Ellipse::Ellipse(Point p, int a, int b) : a(a), b(b) {
	degree = 0;
	lineColor = 15;
	fillColor = 4;

	center = p;
}

Ellipse::~Ellipse() {

}

void Ellipse::drawLine() {
	Grafika::draw_ellipse(center, a, b, degree, lineColor);
}

void Ellipse::fillSmart() {

}

void Ellipse::translate(int x, int y) {

}
void Ellipse::rotate(int theta) {

}
void Ellipse::scale(int width, int height) {

}