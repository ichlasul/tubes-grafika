#include "src/header/Polygon.hpp"

#include "src/header/Grafika.hpp"

Polygon::Polygon() : num(1){
	vertices[0] = Point(0,0);
	lineColor = 15;
	fillColor = 4;
	center = vertices[0];
}

Polygon::Polygon(int num, int * points) : num(num) {
	for (int i = 0; i < num; i++) {
		vertices[i] = Point(points[i * 2], points[(i * 2) + 1]);
	}

	lineColor = 15;
	fillColor = 4;
	center = vertices[0];
}

Polygon::Polygon(int num, Point * points) : num(num) {
	for (int i = 0; i < num; i++) {
		vertices[i] = points[i];
	}

	lineColor = 15;
	fillColor = 4;
	center = vertices[0];
}

Polygon::~Polygon() {
	
}

void Polygon::drawLine() {
	Grafika::draw_poly(num, vertices,lineColor);
}

void Polygon::fillSmart() {
	Grafika::fill_poly(num, vertices, fillColor);
}

void Polygon::translate(int x, int y) {}

void Polygon::rotate(int theta) {}

void Polygon::scale(int width, int height) {}