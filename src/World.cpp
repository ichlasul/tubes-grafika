#include "src/header/World.hpp"
#include "src/header/Grafika.hpp"
#include <graphics.h>

#include <dos.h>

World::World() {
	isRunning = false;
	bg = Bground(60);
    tb = TBoard(30);

	fps = 15;

    int p = 80;
    int l = 80;
    int xc = Grafika::get_maxx() / 2;
    int yc = Grafika::get_maxy() - 100;
    car = Car(xc,yc,p,l);
}

World::~World() {
}

void World::start() {
	isRunning = true;

    bg.firstDraw();
	loop();
}

void World::stop() {
	isRunning = false;
}

void World::loop() {
	while (isRunning) {
		//Grafika::canvas_clear();
		draw();
		update();
        delay(1000 / fps);
        if (tb.isTimeUp()) {
            isRunning = false;
            sb.display(1);  
        }
	}
}

void World::draw() {
	bg.draw();
	obs.draw();
    car.draw();
    tb.draw();
}

void World::update() {
    tb.update();
	checkInput();
	checkCollision();
    obs.update(car);
}

void World::checkInput() {
	int ch;
	//check if a key is pressed
	if (kbhit()) {
        ch = getch();

        // up
        if (ch == 72) {
            sb.display(50);    
            getch();      
        }

        // left
        if(ch == 75) {
            car.moveLeft();
            //agar tidak keluar jalan
            if (getpixel(car.getP1().getX()-car.getSpeed(),car.getP1().getY()) == BROWN) {
                car.moveRight();
            }

        }

        //right
        if(ch == 77) {
            car.moveRight();
            //agar mobil tidak keluar jalan
            if (getpixel(car.getP2().getX()+car.getSpeed(),car.getP2().getY()) == BROWN) {
                car.moveLeft();
            }
        }

        // escape
        if(ch == 27) {
            stop();
        }
    }
}

void World::checkCollision() {
    if (obs.checkCollision()) {
        isRunning = false;
        sb.display(0);
    }
}