#ifndef GRAFIKA_ELLIPSE_HPP
#define GRAFIKA_ELLIPSE_HPP

class Ellipse : public Plane {
public:
	Ellipse();
	~Ellipse();

	void fillEllipse();
	void drawLine();
	void translate(int x, int y);
	void rotate(int theta);
	void scale(int width, int height);

protected:
	int a;
	int b;
	int degree;
	
};
#endif