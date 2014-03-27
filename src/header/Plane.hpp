#include <Point.h>

/**
 * Kelas abstrak yang merepresentasikan bidang
 * Bidang adalah obyek 2 dimensi yang dibatasi garis
 */
class Plane {
public:
	Plane() {};
	~Plane() {};

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
		floodFill();
	}

	/**
	 * Method untuk melakukan translasi
	 */
	void translate(int x, int y) = 0;

	/**
	 * Method untuk melakukan rotasi
	 */
	void rotate(int theta) = 0;

	/**
	 * Method untuk melakukan scaling
	 */
	void scale(int width, int height) = 0;

private:
	/**
	 * Method pewarnaan dengan flood fill
	 */
	void floodFill() {

	}

private:
	/**
	 * Titik tengah bidang
	 * Bisa diasumsikan sebagai titik bakar algoritma Flood Fiil
	 */
	Point center;

	/**
	 * Warna bagian dalam bidang
	 */
	int color;
};