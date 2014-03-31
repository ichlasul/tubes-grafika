#ifndef TBoard_H
#define TBoard_H


#include "src/header/Point.hpp"

class TBoard {
	private:
		Point pos;
		int time;
		int counter;
		bool TimeUp;

	public:
		TBoard();
		~TBoard();
		TBoard(int);

		void update();
		void draw();
		bool isTimeUp();

};
#endif