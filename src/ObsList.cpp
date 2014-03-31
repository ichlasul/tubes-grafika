#include "src/header/ObsList.hpp"

ObsList::ObsList() {
	dBox[0] = Box(Point(300, 200));
	nBox = 1;

	dRock[0] = Rock(Point(320, 120));
	nRock = 1;

	dTire[0] = Tire(Point(380, 300));
	nTire = 1;
}

ObsList::~ObsList() {

}

void ObsList::draw() {
	for (int i = 0; i < nBox; i++) {
		dBox[i].drawLine();
		dBox[i].fillSmart();
	}

	for (i = 0; i < nRock; i++) {
		dRock[i].drawLine();
		dRock[i].fillSmart();
	}

	for (i = 0; i < nTire; i++) {
		dTire[i].drawLine();
		dTire[i].fillSmart();
	}
}