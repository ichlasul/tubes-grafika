#include "src/header/SBoard.hpp" 

#include <graphics.h>
#include <dos.h>
#include <stdio.h>

void SBoard::display(/*int score, */int win) {
	int midx = getmaxx() / 2;
    int midy = getmaxy() / 2;
    int y = 0;
    for (int x = 0; x<(midx/2); x++) {
        int left = midx-x;
        int top = midy-y;
        int right = midx+x;
        int bottom = midy+y;
        
        cleardevice();
        rectangle(left,top,right,bottom);
        delay(5);
        y++;
    }
    
 //    char nbscore[255];
	//  char* scoreLabel = "Score : ";
	// sprintf(nbscore,"%s%d", scoreLabel,score);

    char textWin[255];
    char* isWinLabel = "Anda ";
    char* isWin;
    if (win == 1) {
        isWin = "Menang!";
    } else {
        isWin = "Kalah!";
    }
    sprintf(textWin,"%s%s", isWinLabel,isWin);
	 
     outtextxy((midx*3/4),(midy*3/4),textWin);
     // outtextxy((midx*3/4),midy,nbscore);
}