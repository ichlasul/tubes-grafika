#ifndef GRAFIKA_PLANE_HPP
#define GRAFIKA_PLANE_HPP

#include "src/header/Point.hpp"

/**
 * Kelas abstrak yang merepresentasikan bidang
 * Bidang adalah obyek 2 dimensi yang dibatasi garis
 */
class Plane {
public:

	/**
	 * Method abstrak menggambar garis boundary, sesuai bentuk bendanya
	 */
	virtual void drawLine() = 0;

	/**
	 * Method untuk melakukan pewarnaan
	 * Untuk saat ini bisa menggunakan flood fill
	 * Algoritmanya sama untuk bidang apapun
	 */
	void fill() {
		floodFill(center);
	}

	/**
	 * Method untuk melakukan translasi
	 */
	virtual void translate(int x, int y) = 0;

	/**
	 * Method untuk melakukan rotasi
	 */
	virtual void rotate(int theta) = 0;

	/**
	 * Method untuk melakukan scaling
	 */
	virtual void scale(int width, int height) = 0;

private:
	/**
	 * Method pewarnaan dengan flood fill
	 */
	void floodFill(Point position);

protected:
	/**
	 * Titik tengah bidang
	 * Bisa diasumsikan sebagai titik bakar algoritma Flood Fiil
	 */
	Point center;

	/**
	 * Warna bagian dalam bidang
	 */
	int fillColor;

	/**
	 * Warna garis bidang
	 */
	int lineColor;
};

#endif