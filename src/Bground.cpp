#include "src/header/Bground.hpp"

#include "src/header/Grafika.hpp"

Bground::Bground(int height) : horizon(height) {

}

Bground::~Bground() {

}

void Bground::draw() {
	drawGround();
}

void Bground::drawGround() {
	Grafika::canvas_clear();
	Grafika::canvas_color(6);
}