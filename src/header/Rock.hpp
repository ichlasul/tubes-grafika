#ifndef GRAFIKA_ROCK_HPP
#define GRAFIKA_ROCK_HPP

#include "src/header/Ellipse.hpp"
#include "src/header/Obs.hpp"

class Rock : public Ellipse, public Obs {
public:
	Rock();
	Rock(Point p);
	~Rock();

	virtual void moveCloser();
	virtual bool isCollision(Car car);
	virtual void roll();
	void setPos(int);

private:
	void calculateAB();
	int pos;
};

#endif