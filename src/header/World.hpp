#ifndef GRAFIKA_WORLD_HPP
#define GRAFIKA_WORLD_HPP

#include "src/header/Point.hpp"
#include "src/header/Bground.hpp"
#include "src/header/Car.hpp"
#include "src/header/ObsList.hpp"
#include "src/header/SBoard.hpp"
#include "src/header/Box.hpp"

class World {
public:
	World();
	~World();

	void start();
	void stop();

private:
	void loop();
	void draw();
	void update();
	void checkInput();
	void checkCollision();

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