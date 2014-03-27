#include "G_BASIC.H"

void draw_point_circle(int x0, int y0, int x, int y) {
	int color = 57;

	draw_point(x0 + x, y0 + y, color);
	draw_point(x0 - x, y0 + y, color);
	draw_point(x0 - x, y0 - y, color);
	draw_point(x0 + x, y0 - y, color);
	draw_point(x0 + y, y0 + x, color);
	draw_point(x0 - y, y0 + x, color);
	draw_point(x0 - y, y0 - x, color);
	draw_point(x0 + y, y0 - x, color);
}

void draw_circle(int x0, int y0, int r) {
	int x = 0;
	int y = r;
	int p = 1 - r;

	draw_point_circle(x0, y0, x, y);
	while (x < y) {
		x++;
		if (p < 0) {
			p += 2 * x + 1;
		} else {
			y--;
			p += 2 * (x - y) + 1;
		}
		draw_point_circle(x0, y0, x, y);
	}
}

void draw_point_ellipse(int x0, int y0, int x, int y) {
	int color = 56;

	draw_point(x0 + x, y0 + y, color);
	draw_point(x0 - x, y0 + y, color);
	draw_point(x0 - x, y0 - y, color);
	draw_point(x0 + x, y0 - y, color);
}

/**
 * Belum sempurna
 */
void draw_ellipse(int x0, int y0, int rx, int ry) {
	int rx2 = rx * rx;
	int ry2 = ry * ry;
	int tworx2 = 2 * rx2;
	int twory2 = 2 * ry2;
	int p;
	int x = 0;
	int y = ry;
	int px = 0;
	int py = tworx2 * y;

	if (rx == ry) draw_circle(x0, y0, rx);

	draw_point_ellipse(x0, y0, x, y);

	p = round(ry2 - (rx2 * ry) + (0.25 * rx2));
	while (px < py) {
		x++;
		px += twory2;
		if (p < 0) {
			p += ry2 + px;
		} else {
			y--;
			py -= tworx2;
			p += ry2 + px - py;
		}
		draw_point_ellipse(x0, y0, x, y);
	}

	p = round(ry2 * ( x+ 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2);
	while (y > 0) {
		y--;
		py = tworx2;
		if (p > 0) {
			p += rx2 - py;
		} else {
			x++;
			px += twory2;
			p += rx2 - py + px;
		}
		draw_point_ellipse(x0, y0, x, y);
	}
}