#include "src/header/Obs.hpp"

void Obs::update() {
	if (!isInScene) return;

	if (isMoving) {
		moveCloser();
	} else {
		roll();
	}
}
