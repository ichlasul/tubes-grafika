/**
 * Kelas yang merepresentasikan titik
 */
class Point {
public:
	Point() :x(0), y(0){};
	Point(int x, int y) : x(x), y(y){};
	~Point(){};

public:
	int x;
	int y;
};