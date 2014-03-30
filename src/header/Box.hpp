#ifndef GRAFIKA_BOX_HPP
#define GRAFIKA_BOX_HPP value

#include "src/header/Polygon.hpp"

class Box : public Polygon{
public:
	Box();
	Box(int size);
	~Box();

private:
	int size;
};

#endif