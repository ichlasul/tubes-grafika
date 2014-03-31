#include "src/header/ObsList.hpp"

ObsList::ObsList() {
	 dBox[0] = Box(Point(300, 200));
	 nBox = 1;
}

ObsList::~ObsList() {

}

void ObsList::draw() {
	for (int i = 0; i < nBox; i++) {
		dBox[i].drawLine();
		dBox[i].fillSmart();
	}
}