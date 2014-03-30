#include <stdio.h>

#include "src/header/World.hpp"
#include "src/header/Grafika.hpp"

int main() {
	Grafika::set_usinglibrary(false);

	World world;

	world.start();

	return 0;
}