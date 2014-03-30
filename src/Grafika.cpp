#include "src/header/Grafika.hpp"

#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int Grafika::midx = 0;
int Grafika::midy = 0;

int Grafika::maxx = 0;
int Grafika::maxy = 0;

bool Grafika::is_usinglibrary = false;

void Grafika::canvas_start() {
	int gdriver = DETECT, gmode, errorcode;

	initgraph(&gdriver, &gmode, "C:\\TC\\BGI");

	errorcode = graphresult();
	if (errorcode != grOk) {
		printf("Graphics Error: %s\n", grapherrormsg(errorcode));
		printf("Tekan apapun untuk keluar...");
		getch();
		exit(1);
	}

	midx = getmaxx() / 2;
	midy = getmaxy() / 2;
	maxx = getmaxx();
	maxy = getmaxy();

	//sprintf(msg, "Color 2");
	//outtextxy(midx, midy, msg);
}

void Grafika::canvas_clear() {
	cleardevice();
}

void Grafika::canvas_finish() {
	printf("Tekan apapun untuk keluar...");
	getch();

	closegraph();
}

void Grafika::canvas_color(int color) {
	setbkcolor(color);
}


int Grafika::get_maxx() {
	return maxx;
}
int Grafika::get_maxy() {
	return maxy;
}

void Grafika::set_usinglibrary(bool mode) {
	is_usinglibrary = mode;
}

/**
 * Menggambar sebuah titik dengan warna tertentu
 */
void Grafika::draw_point(int x, int y, int color) {
	//putpixel(midx + x, midy - y, color);
	putpixel(x, y, color);
}


/**
 * Menggambar garis dengan metode fpc
 * Garis akan berwarna lightred
 *
 */
void Grafika::draw_line_FPC(int x1, int y1, int x2, int y2) {
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
void Grafika::draw_line_DDA(int x1, int y1, int x2, int y2) {
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
void Grafika::draw_line_Bres(int x1, int y1, int x2, int y2) {
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


void Grafika::draw_line_vertical(int x, int y1, int y2, int color) {
	for (int i = y1; i <= y2; i++) {
		draw_point(x, 	i, color);
	}
}

void Grafika::draw_line_horizontal(int x1, int x2, int y, int color) {
	for (int i = x1; i <= x2; i++) {
		draw_point(i, y, color);
	}

}

void Grafika::draw_poly(int num, Point * vertices) {
	if (is_usinglibrary) {
		int * points = new int[(num + 1) * 2];
		for (int i = 0; i < num; i++) {
			points[2 * i] = vertices[i].getX();
			points[(2 * i) + 1] = vertices[i].getY();
			//printf("%d, %d\n", vertices[i].getX(),vertices[i].getY());
		}
		points[2 * num] = vertices[0].getX();
		points[(2 * num) + 1] = vertices[0].getY();

		drawpoly(num + 1, points);
		setfillstyle(SOLID_FILL, 9);
		fillpoly(num, points);
	} else {
		for (int i = 0; i < num - 1; i++) {
			draw_line_DDA(vertices[i].getX(), vertices[i].getY(),vertices[i + 1].getX(), vertices[i + 1].getY());
			printf("%d\n", num);
		}
		draw_line_DDA(vertices[num - 1].getX(), vertices[num - 1].getY(),vertices[0].getX(), vertices[0].getY());
	}
}

void Grafika::draw_point_circle(int x0, int y0, int x, int y) {
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

void Grafika::draw_circle(int x0, int y0, int r) {
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

void Grafika::draw_point_ellipse(int x0, int y0, int x, int y) {
	int color = 56;

	draw_point(x0 + x, y0 + y, color);
	draw_point(x0 - x, y0 + y, color);
	draw_point(x0 - x, y0 - y, color);
	draw_point(x0 + x, y0 - y, color);
}

/**
 * Belum sempurna
 */
void Grafika::draw_ellipse(int x0, int y0, int rx, int ry) {
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


void Grafika::flood_fill(Point position, int fillColor, int lineColor) {
	if (is_usinglibrary) {
		setfillstyle(SOLID_FILL, fillColor);
		floodfill(position.getX(), position.getY(), lineColor);
	} else {
		floodFillNaive(position, fillColor, lineColor);
	}

}

void Grafika::floodFillNaive(Point pos, int fill, int border) {
	if (getpixel(pos.getX(), pos.getY()) == border) return;
	if (getpixel(pos.getX(), pos.getY()) == fill) return;
	if (pos.isOutOfBound()) return;

	putpixel(pos.getX(), pos.getY(), fill);
	floodFillNaive(pos.up(), fill, border);
	floodFillNaive(pos.right(), fill, border);
	floodFillNaive(pos.down(), fill, border);
	floodFillNaive(pos.left(), fill, border);
}