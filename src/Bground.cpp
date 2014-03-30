#include "src/header/Bground.hpp"

#include "src/header/Grafika.hpp"

Bground::Bground() : horizon(40) {
	Point point[4];

	point[0] = Point(0,0);
	point[1] = Point(Grafika::get_maxx(), 0);
	point[2] = Point(Grafika::get_maxx(), horizon);
	point[3] = Point(0, horizon);

	sky = Polygon(4, point);
	sky.setCenter(Point(Grafika::get_maxx() / 2, horizon / 2));
	sky.setLineColor(WHITE);
	sky.setFillColor(LIGHTBLUE);
}

Bground::Bground(int height) : horizon(height) {
	Point point[4];

	point[0] = Point(0,0);
	point[1] = Point(Grafika::get_maxx(), 0);
	point[2] = Point(Grafika::get_maxx(), horizon);
	point[3] = Point(0, horizon);

	sky = Polygon(4, point);
	sky.setCenter(Point(Grafika::get_maxx() / 2, horizon / 2));
	sky.setLineColor(WHITE);
	sky.setFillColor(LIGHTBLUE);
}

Bground::~Bground() {

}

void Bground::draw() {
	drawGround();
	drawSky();
}

void Bground::drawGround() {
	//Grafika::canvas_clear();
	Grafika::canvas_color(6);
}

void Bground::drawSky() {
	sky.drawLine();
	sky.fill();
}