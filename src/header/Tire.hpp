#ifndef GRAFIKA_TIRE_HPP
#define GRAFIKA_TIRE_HPP

#include "src/header/Ellipse.hpp"
#include "src/header/Obs.hpp"

class Tire : public Ellipse, public Obs {
public:
	Tire();
	~Tire();

	virtual void moveCloser();
	virtual bool isCollision(Car car);
	virtual void roll();
};
#endif