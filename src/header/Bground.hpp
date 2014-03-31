#ifndef GRAFIKA_BACKGROUND_HPP
#define GRAFIKA_BACKGROUND_HPP

#include "src/header/Polygon.hpp"

class Bground {
public:
	Bground();
	Bground(int height);
	~Bground();

	void draw();
	void firstDraw();

private:
	void initGround();
	void initSky();
	void initRoad();

	void drawGround();
	void drawSky();
	void drawRoad();

private:
	Polygon sky;
	Polygon road;
	Polygon ground;

	int horizon;
	
};
#endif