#ifndef GRAFIKA_ELLIPSE_HPP
#define GRAFIKA_ELLIPSE_HPP

#include "src/header/Plane.hpp"

class Ellipse : public Plane {
public:
	Ellipse();
	Ellipse(Point p, int a, int b);
	~Ellipse();

	void fillSmart();
	void drawLine();
	void translate(int x, int y);
	void rotate(int theta);
	void scale(int width, int height);

protected:
	int a;
	int b;
	int degree;
	
};
#endif