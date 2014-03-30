#include "src/header/World.hpp"
#include "src/header/Grafika.hpp"

World::World() : bg(20) {
	isRunning = false;
	Grafika::canvas_start();

	start();
}

World::~World() {
	Grafika::canvas_finish();
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