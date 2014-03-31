#include "src/header/Bground.hpp"

#include "src/header/Grafika.hpp"

Bground::Bground() : horizon(40) {
	initGround();
	initSky();
	initRoad();
}

Bground::Bground(int height) : horizon(height) {
	initGround();
	initSky();
	initRoad();
}

Bground::~Bground() {

}

void Bground::initGround() {
	Point point[4];

	point[0] = Point(0, horizon);
	point[1] = Point(Grafika::get_maxx(), horizon);
	point[2] = Point(Grafika::get_maxx(), Grafika::get_maxy());
	point[3] = Point(0, Grafika::get_maxy());

	ground = Polygon(4, point);
	ground.setCenter(Point(Grafika::get_maxx() / 2, Grafika::get_maxy()));
	ground.setLineColor(BROWN);
	ground.setFillColor(BROWN);
}

void Bground::initSky() {
	Point point[4];

	point[0] = Point(0,0);
	point[1] = Point(Grafika::get_maxx(), 0);
	point[2] = Point(Grafika::get_maxx(), horizon);
	point[3] = Point(0, horizon);

	sky = Polygon(4, point);
	sky.setCenter(Point(Grafika::get_maxx() / 2, horizon / 2));
	sky.setLineColor(LIGHTBLUE);
	sky.setFillColor(LIGHTBLUE);
}

void Bground::initRoad() {
	Point point[4];
	int a = Grafika::get_maxx() * 0.02;
	int b = Grafika::get_maxx() * 0.4;

	point[0] = Point(Grafika::get_maxx() / 2 - a, horizon);
	point[1] = Point(Grafika::get_maxx() / 2 + a, horizon);
	point[2] = Point(Grafika::get_maxx() / 2 + b, Grafika::get_maxy());
	point[3] = Point(Grafika::get_maxx() / 2 - b, Grafika::get_maxy());

	road = Polygon(4, point);
	road.setCenter(Point(Grafika::get_maxx() / 2, Grafika::get_maxy() / 2 + horizon));
	road.setLineColor(DARKGRAY);
	road.setFillColor(LIGHTGRAY);
}

void Bground::draw() {
	drawRoad();
	drawSky();
}

void Bground::firstDraw() {
	drawGround();
	drawSky();
}

void Bground::drawGround() {
	//Grafika::canvas_clear();
	//Grafika::canvas_color(6);

	ground.drawLine();
	ground.fillSmart();
}

void Bground::drawSky() {
	sky.drawLine();
	//sky.fill();
	sky.fillSmart();
}

void Bground::drawRoad() {
	road.drawLine();
	//road.fill();
	road.fillSmart();
}