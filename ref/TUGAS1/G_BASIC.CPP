#include "G_BASIC.H"
#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void canvas_start() {
	int gdriver = DETECT, gmode, errorcode;

	initgraph(&gdriver, &gmode, "C:\\TC\\BGI");

	errorcode = graphresult();
	if (errorcode != grOk) {
		printf("Graphics Error: %s\n", grapherrormsg(errorcode));
		printf("Tekan apapun untuk keluar...");
		getch();
		exit(1);
	}

	setcolor(0);

	midx = getmaxx() / 2;
	midy = getmaxy() / 2;
}

void canvas_clear() {
	cleardevice();
}

void canvas_finish() {
	printf("Tekan apapun untuk keluar...");
	getch();

	closegraph();
}

/**
 * Menggambar sebuah titik dengan warna tertentu
 */
void draw_point(int x, int y, int color) {
	putpixel(midx + x, midy - y, color);
}

/**
 * Menggambar garis sumbu x dan y
 */
void draw_axes() {
	for (int i = -midx; i < midx; i++) {
		if (i % 2 == 0) {
			draw_point(i, 0, WHITE);
			draw_point(0, i, WHITE);
		}
	}
}

/**
 * Tidak Dipakai
 *
 * Mendapatkan section dari suatu garis
 * Section diperoleh dengan mentransformasikan ke kartesius
 * Dengan titik O menjadi titik awal garis
 * Sehingga bisa diketahui arah pergerakan garis yang nanti akan digambar
 * Section dibagi 8, dibatasi X, Y, dan diagonal
 *   \   3  |  2   /
 *     \    |    /
 *   4   \  |  /   1
 * ________\|/_______
 *         /|\
 *   5   /  |  \  8
 *     /    |    \
 *   /  6   |  7   \
 */
int get_section(int x1, int y1, int x2, int y2) {
	int dx = x2 - x1;
	int dy = y2 - y1;

	//di kanan sumbu y (1,2,7,8)
	if (dx > 0) {
		//di atas sumbu x (1,2)
		if (dy > 0) {
			return dx > dy ? 1 : 2;
		} else {
			return dx > abs(dy) ? 8 : 7;
		}
	//di kiri sumbu y (3,4,5,6)
	} else {
		//di atas sumbu x (3,4)
		if (dy > 0) {
			return abs(dx) > dy ? 4 : 3;
		} else {
			return abs(dx) > abs(dy) ? 5 : 6;
		}
	}
}
