#ifndef GRAFIKA_GRAFIKA_HPP
#define GRAFIKA_GRAFIKA_HPP

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

	static int getMaxX();
	static int getMaxY();

	static void draw_point(int x1, int x2, int color);

	static void draw_line_FPC(int x1, int y1, int x2, int y2);
	static void draw_line_DDA(int x1, int y1, int x2, int y2);
	static void draw_line_Bres(int x1, int y1, int x2, int y2);
	static void draw_line_vertical(int x, int y1, int y2, int color);
	static void draw_line_horizontal(int x1, int x2, int y, int color);

	static void draw_circle(int x0, int y0, int r);
	static void draw_ellipse(int x0, int y0, int rx, int ry);

private:
	static void draw_point_circle(int x0, int y0, int x, int y);
	static void draw_point_ellipse(int x0, int y0, int x, int y);

private:
	static int midx;
	static int midy;

	static int maxx;
	static int maxy;	
};

#endif