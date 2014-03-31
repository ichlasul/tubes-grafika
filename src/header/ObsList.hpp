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

	void update(Car car);
	bool checkCollision();

private:
	//biar gmpang, static aja
	//satu2 tiap obs biar gampang
	Box dBox[3];
	int nBox;

	Tire dTire[3];
	int nTire;

	Rock dRock[3];
	int nRock;

	int randObs[500];
	int numbObs[500];
	int nbObs;
	int counter;
	bool isCollision;
};
#endif