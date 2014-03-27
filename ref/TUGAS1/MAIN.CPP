#include "G_BASIC.H"
#include "G_LINE.H"
#include "G_CIRCLE.H"

void test_line_FPC(int a, int b, int c, int d) {
	draw_line_FPC(a, b, c, d);
	draw_line_FPC(b, a, d, c);
	draw_line_FPC(-b, a, -d, c);
	draw_line_FPC(-a, b, -c, d);
	draw_line_FPC(-a, -b, -c, -d);
	draw_line_FPC(-b, -a, -d, -c);
	draw_line_FPC(b, -a, d, -c);
	draw_line_FPC(a, -b, c, -d);
}

void test_line_DDA(int a, int b, int c, int d) {
	draw_line_DDA(a, b, c, d);
	draw_line_DDA(b, a, d, c);
	draw_line_DDA(-b, a, -d, c);
	draw_line_DDA(-a, b, -c, d);
	draw_line_DDA(-a, -b, -c, -d);
	draw_line_DDA(-b, -a, -d, -c);
	draw_line_DDA(b, -a, d, -c);
	draw_line_DDA(a, -b, c, -d);
}

void test_line_Bres(int a, int b, int c, int d) {
	draw_line_Bres(a, b, c, d);
	draw_line_Bres(b, a, d, c);
	draw_line_Bres(-b, a, -d, c);
	draw_line_Bres(-a, b, -c, d);
	draw_line_Bres(-a, -b, -c, -d);
	draw_line_Bres(-b, -a, -d, -c);
	draw_line_Bres(b, -a, d, -c);
	draw_line_Bres(a, -b, c, -d);
}

void test_circle(int a, int b, int c) {
	draw_circle(a, b, c);
	draw_circle(-a, b, c);
	draw_circle(-a, -b, c);
	draw_circle(a, -b, c);
}

void test_ellipse(int a, int b, int c, int d) {
	draw_ellipse(a, b, c, d);
	draw_ellipse(-a, b, c, d);
	draw_ellipse(-a, -b, c, d);
	draw_ellipse(a, -b, c, d);
}


int main() {
	canvas_start();

	for (int i = 0; i < 150; i++) {
		int x = i % 50;

		draw_axes();

		test_line_FPC(30, x + 0, x + 200, (120 - x) + 50);
		test_line_DDA(30, x + 5, x + 200, (120 - x) + 55);
		test_line_Bres(30, x + 10, x + 200, (120 - x) + 60);
		test_circle(40 + x, 40 + x, 20 + x);
		test_ellipse(60 + x, 60 + x, 30, 30 + x);

		if (x % 3 == 0) canvas_clear();
	}

	canvas_finish();
	return 0;
}