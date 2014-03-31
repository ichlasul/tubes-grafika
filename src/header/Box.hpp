#ifndef GRAFIKA_BOX_HPP
#define GRAFIKA_BOX_HPP value

#include "src/header/Polygon.hpp"
#include "src/header/Obs.hpp"

class Box : public Polygon, public Obs {
public:
	Box();
	Box(Point p);
	~Box();

	virtual void moveCloser();
	virtual bool isCollision(Car car);
	virtual void roll();
	void setPos(int);

private:
	void calculateVertices();

private:
	int size;
	int pos;
};

#endif