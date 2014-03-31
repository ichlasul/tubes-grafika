#include "src/header/Car.hpp"

#include <graphics.h>

Car::Car() {
	posX = 0;
	posY = 0;
	panjang = 0;
	lebar = 0;

	speed = 20;
}

Car::~Car() {

}

Car::Car(int _posX, int _posY, int _panjang, int _lebar) {
	posX = _posX;
	posY = _posY;
	panjang = _panjang;
	lebar = _lebar;

	speed = 25;
}

void Car::draw() {
	int left = posX - lebar/2;
	int right = left + lebar;
	int top = posY + panjang/4;
	int bottom = posY + panjang/2;
	rectangle(left,top,right,bottom);

	int ax1 = posX - (lebar/2*3/4);
	int ax2 = posX + lebar/2*3/4;
	int ay = bottom - panjang;
	line(ax1,ay,ax2,ay);
	line(ax1,ay,left,top);
	line(ax2,ay,right,top);
	p1 = Point(ax1,ay);
	p2 = Point(ax2,ay);
}

void Car::moveLeft() {
	posX = posX - speed;
}

void Car::moveRight() {
	posX = posX + speed;
}

int Car::getPosX() {
	return posX;
}

int Car::getPosY() {
	return posY;
}

int Car::getPanjang() {
	return panjang;
}

int Car::getLebar() {
	return lebar;
}

void Car::setPosX(int _posX) {
	posX = _posX;
}

void Car::setPosY(int _posY) {
	posY = _posY;
}

void Car::setPanjang(int _panjang) {
	panjang = _panjang;
}

void Car::setLebar(int _lebar) {
	lebar = _lebar;
}

Point Car::getP1() {
	return p1;
}

Point Car::getP2() {
	return p2;
}

int Car::getSpeed() {
	return speed;
}