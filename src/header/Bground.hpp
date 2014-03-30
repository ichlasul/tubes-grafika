#ifndef GRAFIKA_BACKGROUND_HPP
#define GRAFIKA_BACKGROUND_HPP

#include "src/header/Polygon.hpp"

class Bground {
public:
	Bground(int height);
	~Bground();

	void draw();

private:
	void drawGround();
	void drawSky();
	void drawRoad();

private:
	Polygon road;

	int horizon;
	
};
#endif