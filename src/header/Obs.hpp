#ifndef GRAFIKA_OBSTACLE_HPP
#define GRAFIKA_OBSTACLE_HPP value

#include "src/header/Boolean.h"

class Obs {
public:
	virtual void isCollision() = 0;

	void update();

	virtual void moveCloser() = 0;
	virtual void roll() = 0;

protected:
	bool isMoving;
	bool isInScene;
};


#endif