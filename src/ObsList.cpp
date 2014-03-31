#include "src/header/ObsList.hpp"
#include "src/header/Grafika.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

ObsList::ObsList() {
	// dBox[0] = Box(Point(Grafika::get_maxx()/2, 60));
	nBox = 0;

	// dRock[0] = Rock(Point(Grafika::get_maxx()/2, 60));
	nRock = 0;

	// dTire[0] = Tire(Point(Grafika::get_maxx()/2, 60));
	nTire = 0;
	nbObs = 0;
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

void ObsList::update() {
	counter++;
	if ((counter % 110) == 0) {
		srand (time(NULL));
		int randm = rand() % 3;
		// srand (time(NULL));
		int pos = rand() % 3;
		if (randm == 0) {
			randObs[nbObs] = 0;
			numbObs[nbObs] = nBox;
			dBox[nBox] = Box(Point(Grafika::get_maxx()/2, 60));
			if (pos == 2) {pos = -1;}
			dBox[nBox].setPos(pos);
			nBox++;
		}
		if (randm == 1) {
			randObs[nbObs] = 1;
			numbObs[nbObs] = nTire;
			dTire[nTire] = Tire(Point(Grafika::get_maxx()/2, 60));
			if (pos == 2) {pos = -1;}
			dTire[nTire].setPos(pos);
			nTire++;
		}
		if (randm == 2) {
			randObs[nbObs] = 2;
			numbObs[nbObs] = nRock;
			dRock[nRock] = Rock(Point(Grafika::get_maxx()/2, 60));
			if (pos == 2) {pos = -1;}
			dRock[nRock].setPos(pos);
			nRock++;
		}

		nbObs++;
	}

	for (int i=0; i<nbObs; i++) {
		int obs = randObs[i];
		int idx = numbObs[i];

		if (obs == 0) {
			dBox[idx].moveCloser();
		}
		if (obs == 1) {
			dTire[idx].moveCloser();
		}
		if (obs == 2) {
			dRock[idx].moveCloser();
		}
	}

	// for (int i = 0; i < nBox; i++) {
	// 	dBox[i].moveCloser();
	// }

	// for (i = 0; i < nRock; i++) {
	// 	dRock[i].moveCloser();
	// }

	// for (i = 0; i < nTire; i++) {
	// 	dTire[i].moveCloser();
	// }
}