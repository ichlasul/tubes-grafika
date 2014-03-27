/**
 * Kelas yang merepresentasikan titik
 */
class Point {
public:
	Point() :x(0), y(0){};
	Point(int x, int y) : x(x), y(y){};
	~Point(){};

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	bool isOutOfBound() {
		return x >= 0 && x < 640 && y >= 0 && y < 480;
	}

	Point up() {
		return new Point(x, y - 1);
	}

	Point down() {
		return new Point(x, y + 1);
	}

	Point left() {
		return new Point(x - 1, y);
	}

	Point right() {
		return new Point(x + 1, y);
	}

private:
	int x;
	int y;
};