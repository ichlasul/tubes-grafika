#ifndef GRAFIKA_OBSTACLES_LIST_HPP
#define GRAFIKA_OBSTACLES_LIST_HPP

#include "src/header/Obs.hpp"
#include "src/header/Box.hpp"
#include "src/header/Rock.hpp"
#include "src/header/Tire.hpp"

class ObsList {
public:
	ObsList();
	~ObsList();

	void draw();

private:
	//biar gmpang, static aja
	//satu2 tiap obs biar gampang
	Box dBox[3];
	int nBox;

	Tire dTire[3];
	int nTire;

	Rock dRock[3];
	int nRock;
};
#endif