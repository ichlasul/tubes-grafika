#ifndef GAME_H
#define GAME_H

#include <graphics.h>
#include <process.h>
#include <dos.h>
#include <conio.h>
 #include <stdlib.h>
#include <dos.h>
#include <iostream.h>
#include <string.h>
 #include <stdio.h>

class Game {
	private:
		int isWin;

	public:	
		Game();
		~Game();
		
		
		void scoreboard(int,int);
};

#endif