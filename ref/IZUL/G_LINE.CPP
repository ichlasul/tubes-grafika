#include "G_BASIC.H"
#include "G_LINE.H"
#include <math.h>

/**
 * Menggambar garis dengan metode fpc
 * Garis akan berwarna lightred
 *
 */
void draw_line_FPC(int x1, int y1, int x2, int y2) {
	int dx = x2 - x1;
	int dy = y2 - y1;
	int xa = x1;
	int xb = x2;
	int ya = y1;
	int yb = y2;
	int x, y;
	float m;
	int color = 60;

	if (dx == 0) draw_line_vertical(x1, y1, y2, color);
	if (dy == 0) draw_line_horizontal(x1, x2, y1, color);

	if (abs(dx) > abs(dy)) {
		m = dy / (float) dx;

		if (x2 < x1) {
			xa = x2;
			xb = x1;
		}

		for (x = xa; x < xb; x++) {
			y = (int) (m * (x - x1)) + y1;
			draw_point(x, y, color);
		}
	} else {
		m = dx / (float) dy;

		if (y2 < y1) {
			ya = y2;
			yb = y1;
		}

		for (y = ya; y < yb; y++) {
			x = (int) (m * (y - y1)) + x1;
			draw_point(x, y, color);
		}
	}
}

/**
 * Menggambar garis dengan metode fpc
 * Garis akan berwarna lightblue
 *
 */
void draw_line_DDA(int x1, int y1, int x2, int y2) {
	int dx = x2 - x1;
	int dy = y2 - y1;
	int steps;
	float x_inc, y_inc;
	float x = x1;
	float y = y1;
	int color = 59;

	if (dx == 0) draw_line_vertical(x1, y1, y2, color);
	if (dy == 0) draw_line_horizontal(x1, x2, y1, color);

	if (abs(dx) > abs(dy)) {
		steps = abs(dx);
	} else {
		steps = abs(dy);
	}

	x_inc = dx / (float) steps;
	y_inc = dy / (float) steps;

	draw_point(round(x), round(y), color);
	for (int i = 0; i < steps; i++) {
		x += x_inc;
		y += y_inc;

		draw_point(round(x), round(y), color);
	}

}

/**
 * Menggambar garis dengan metode fpc
 * Garis akan berwarna lightgreen
 * Untuk sementara hanya bisa untuk garis dengan 0 <= m <= 1
 */
void draw_line_Bres(int x1, int y1, int x2, int y2) {
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int p = 2 * dy - dx;
	int a = 2 * dy;
	int b = 2 * (dy - dx);
	int x = x1;
	int y = y1;
	int xb = x2;
	int yb = y2;
	int color = 58;

	if (dx == 0) draw_line_vertical(x1, y1, y2, color);
	if (dy == 0) draw_line_horizontal(x1, x2, y1, color);

	if (dx > dy) {
		if (x1 > x2) {
			x = x2;
			y = y2;
			xb = x1;
		}

		draw_point(x, y, color);

		while (x < xb) {
			x++;

			if (p < 0) {
				p += a;
			} else {
				y++;
				p += b;
			}

			draw_point(x, y, color);
		}
	}
}


void draw_line_vertical(int x, int y1, int y2, int color) {
	for (int i = y1; i <= y2; i++) {
		draw_point(x, 	i, color);
	}
}

void draw_line_horizontal(int x1, int x2, int y, int color) {
	for (int i = x1; i <= x2; i++) {
		draw_point(i, y, color);
	}

}
