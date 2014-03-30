#ifndef GRAFIKA_WORLD_HPP
#define GRAFIKA_WORLD_HPP

#include "src/header/Point.hpp"
#include "src/header/Bground.hpp"
#include "src/header/Car.hpp"
#include "src/header/ObsList.hpp"
#include "src/header/SBoard.hpp"

class World {
public:
	World();
	~World();


private:
	Bground bg;
	Car car;
	ObsList obs;
	SBoard sb;
	int isRunning;
	int timer;
	int lastUpdateTime;
	int fps;
};

#endif