#ifndef GRAFIKA_POLYGON_HPP
#define GRAFIKA_POLYGON_HPP

#include "src/header/Plane.hpp"
#include "src/header/Point.hpp"

class Polygon : public Plane {
public:
	Polygon();
	Polygon(int num, int * points);
	Polygon(int num, Point * points);
	~Polygon();

	int getNum();
	int* getPoints();

	void fillPoly();
	void drawLine();
	void translate(int x, int y);
	void rotate(int theta);
	void scale(int width, int height);

private:
	Point * vertices;
	int num;
};

#endif