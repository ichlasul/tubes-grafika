#ifndef GRAFIKA_POLYGON_HPP
#define GRAFIKA_POLYGON_HPP

#include "src/header/Plane.hpp"

class Polygon : public Plane {
public:
	Polygon();
	~Polygon();

	void fillPoly();
	void drawLine();
	void translate(int x, int y);
	void rotate(int theta);
	void scale(int width, int height);

private:
	int * vertices;
	int num;
};

#endif