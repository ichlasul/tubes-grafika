#ifndef GRAFIKA_POINT_HPP
#define GRAFIKA_POINT_HPP

#include "src/header/Boolean.h"

/**
 * Kelas yang merepresentasikan titik
 */
class Point {
public:
	Point();
	Point(int x, int y);
	~Point();

	int getX();
	int getY();

	/**
	 * Memeriksa apakah titik berada di luar batas layar
	 */
	bool isOutOfBound();

	/**
	 * Mengembalikan titik di atas titik semula
	 */
	Point up();

	/**
	 * Mengembalikan titik di bawah titik semula
	 */
	Point down();

	/**
	 * Mengembalikan titik di kiri titik semula
	 */
	Point left();

	/**
	 * Mengembalikan titik di kanan titik semula
	 */
	Point right();

private:
	int x;
	int y;
};

#endif