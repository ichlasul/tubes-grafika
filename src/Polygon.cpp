#include "src/header/Polygon.hpp"

#include <stdlib.h>

Polygon::Polygon() : num(1){
	vertices = (Point *) malloc(sizeof(Point));
	vertices[0] = Point(0,0);
}

Polygon::Polygon(int num, int * points) : num(num) {
	vertices = (Point *) malloc(num * sizeof(Point));

	for (int i = 0; i < num; i++) {
		vertices[i] = Point(points[i * 2], points[(i * 2) + 1]);
	}
}

Polygon::Polygon(int num, Point * points) : num(num) {
	vertices = (Point *) malloc(num * sizeof(Point));

	for (int i = 0; i < num; i++) {
		vertices[i] = points[i];
	}
}

Polygon::~Polygon() {
	free(vertices);
}

int Polygon::getNum() {
	return num;
}

int* Polygon::getPoints() {

}

void Polygon::drawLine() {

}

void Polygon::fillPoly() {

}

void Polygon::translate(int x, int y) {}

void Polygon::rotate(int theta) {}

void Polygon::scale(int width, int height) {}