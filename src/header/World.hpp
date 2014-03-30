#ifndef GRAFIKA_WORLD_HPP
#define GRAFIKA_WORLD_HPP

#include "src/Header/Background.hpp"
#include "src/Header/Car.hpp"
#include "src/Header/ObstaclesList.hpp"
#include "src/Header/ScoreBoard.hpp"

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