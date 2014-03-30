#include "src/Header/World.hpp"

void World::World() {
	isRunning = false;
}

void World::start() {
	isRunning = true;

	loop();
}

void World::stop() {
	isRunning = false;
}

void World::loop() {
	while (isRunning) {
		draw();
		update();
	}
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