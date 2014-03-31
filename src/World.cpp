#include "src/header/World.hpp"
#include "src/header/Grafika.hpp"

#include <dos.h>

World::World() {
	isRunning = false;
	bg = Bground(60);

	fps = 15;

    int p = 100;
    int l = 100;
    int xc = Grafika::get_maxx() / 2;
    int yc = Grafika::get_maxy() - 60;
    car = Car(xc,yc,p,l);
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
	while (isRunning) {
		Grafika::canvas_clear();
		draw();
		update();
        delay(1000 / fps);
	}
}

void World::draw() {
	bg.draw();
	car.draw();
	obs.draw();
}

void World::update() {
	checkInput();
	checkCollision();
}

void World::checkInput() {
	int ch;
	//check if a key is pressed
	if (kbhit()) {
        ch = getch();

        // up
        if (ch == 72) {
            sb.display(50,1);    
            getch();      
        }

        // left
        if(ch == 75) {
            car.moveLeft();

        }

        //right
        if(ch == 77) {
            car.moveRight();
        }

        // escape
        if(ch == 27) {
            stop();
        }
    }
}

void World::checkCollision() {

}