#ifndef GRAFIKA_BACKGROUND_HPP
#define GRAFIKA_BACKGROUND_HPP

class Bground {
public:
	Bground();
	~Bground();

	void draw();

private:
	Polygon sky;
	Polygon road;

	int horizon;
	
};
#endif