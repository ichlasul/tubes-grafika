#ifndef GRAFIKA_GRAFIKA_HPP
#define GRAFIKA_GRAFIKA_HPP

#include "src/header/Point.hpp"
#include "src/header/Boolean.h"

#include <conio.h>

#define round(x) ((int) (x + 0.5))

class Grafika {
private:
	Grafika() {};
	~Grafika() {};

public:
	static void canvas_start();
	static void canvas_clear();
	static void canvas_finish();
	static void canvas_color(int color);

	static int get_maxx();
	static int get_maxy();

	static void set_usinglibrary(bool mode);

	static void draw_point(int x1, int x2, int color);

	static void draw_line_FPC(int x1, int y1, int x2, int y2);
	static void draw_line_DDA(int x1, int y1, int x2, int y2);
	static void draw_line_Bres(int x1, int y1, int x2, int y2);
	static void draw_line_vertical(int x, int y1, int y2, int color);
	static void draw_line_horizontal(int x1, int x2, int y, int color);

	static void draw_poly(int num, Point * vertices, int color);
	static void draw_ellipse(Point center, int a, int b, int degree, int lineColor);

	static void draw_circle(int x0, int y0, int r);
	static void draw_ellipse(int x0, int y0, int rx, int ry);

	static void flood_fill(Point seed, int fill, int border);
	static void fill_poly(int num, Point * vertices, int fill);
	static void fill_ellipse(Point center, int a, int b, int degree, int fillColor);

private:
	static void draw_point_circle(int x0, int y0, int x, int y);
	static void draw_point_ellipse(int x0, int y0, int x, int y);

	static void floodFillNaive(Point pos, int fill, int border);

private:
	static int midx;
	static int midy;

	static int maxx;
	static int maxy;

	static bool is_usinglibrary;
};

#endif