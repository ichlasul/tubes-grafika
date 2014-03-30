#ifndef GRAFIKA_CAR_HPP
#define GRAFIKA_CAR_HPP

#include "src/header/Polygon.hpp"

class Car : public Polygon {

public:	
	Car();
	~Car();
	Car(int, int, int, int);
	void draw();
	void moveLeft();
	void moveRight();
	int getPosX();
	int getPosY();
	int getPanjang();
	int getLebar();
	void setPosX(int);
	void setPosY(int);
	void setPanjang(int);
	void setLebar(int);


private:
	int posX;
	int posY;
	int panjang;
	int lebar;
};
#endif