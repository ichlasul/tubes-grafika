#include "src/header/World.hpp"
#include "src/header/Grafika.hpp"

World::World() {
	isRunning = false;
	bg = Bground(80);
}

World::~World() {
}

void World::start() {
	isRunning = true;

	loop();
}

void World::stop() {
	isRunning = false;
}

void World::loop() {
	//while (isRunning) {
		draw();
		update();
	//}
}

void World::draw() {
	bg.draw();
}

void World::update() {
	checkInput();
	checkCollision();
}

void World::checkInput() {

}

void World::checkCollision() {

}

void World::delay(int time) {
	
}