#ifndef GRAFIKA_WORLD_HPP
#define GRAFIKA_WORLD_HPP

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