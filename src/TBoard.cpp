#include "src/header/TBoard.hpp"
#include "src/header/Grafika.hpp"
#include <graphics.h>
#include <dos.h>
#include <stdio.h>

TBoard::TBoard() {
	pos = Point(10,10);
	time = 0;
	counter = 0;
	TimeUp = false;
}

TBoard::TBoard(int _time) {
	pos = Point(10,10);
	time = _time*15;
	TimeUp = false;
	counter = _time;
}

TBoard::~TBoard() {

}

void TBoard::update() {
	if (time == 0) {
		TimeUp = true;
	} else {
		time--;
	}
	
}

void TBoard::draw() {
	setcolor(BLACK);
	int left = pos.getX();
	int top = pos.getY();
	int right = left + 80;
	int bottom = top + 20;
	if ((time % 15) == 0) { if (time > 0) counter--; } 
	rectangle(left,top,right,bottom);
	char txtTime[255];
	char* lblTime = "Time : ";
	sprintf(txtTime,"%s%d", lblTime,counter);
	 
    outtextxy(15,15,txtTime);
}


bool TBoard::isTimeUp() {
	return TimeUp;
}