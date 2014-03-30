#ifndef GRAFIKA_WORLD_HPP
#define GRAFIKA_WORLD_HPP

#include "src/header/Point.hpp"
#include "src/header/Background.hpp"
#include "src/header/Car.hpp"
#include "src/header/ObstaclesList.hpp"
#include "src/header/ScoreBoard.hpp"

class World {
public:
	World();
	~World();


private:
	Background bg;
	Car car;
	ObstaclesList obs;
	ScoreBoard sb;
	int isRunning;
	int timer;
	int lastUpdateTime;
	int fps;
};

#endif