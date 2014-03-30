#include <stdio.h>

#include "src/header/World.hpp"
#include "src/header/Grafika.hpp"

int main() {
	Grafika::set_usinglibrary(true);
	Grafika::canvas_start();

	World world;
	world.start();

	Grafika::canvas_finish();
	return 0;
}