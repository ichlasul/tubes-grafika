#ifndef CAR_H
#define CAR_H

#include <graphics.h>
#include <process.h>
#include <dos.h>
#include <conio.h>

class Car {
	private:
		int posX;
		int posY;
		int panjang;
		int lebar;

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
};

#endif


