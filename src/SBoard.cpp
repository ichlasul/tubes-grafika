#include "src/header/SBoard.hpp" 

#include <graphics.h>
#include <dos.h>
#include <stdio.h>
#include "src/header/Point.hpp"

void ffill4(int x,int y,int fcolor,int ocolor)
 {
          int current;
          current = getpixel(x,y);
          
          if(current == ocolor)
          {
               putpixel(x,y,fcolor);
               
                ffill4(x+1,y,fcolor,ocolor);
               ffill4(x-1,y,fcolor,ocolor);
               ffill4(x,y+1,fcolor,ocolor);
               ffill4(x,y-1,fcolor,ocolor);
               
          }
 }

void SBoard::display(/*int score, */int win) {
    int midx = getmaxx() / 2;
    int midy = getmaxy() / 2;
    int y = 0;
    int left, top, right, bottom;
    for (int x = 0; x<(midx/3); x++) {
         left = midx-x;
         top = midy-y;
         right = midx+x;
         bottom = midy+y;
        
        // cleardevice();
         setcolor(WHITE);
        rectangle(left,top,right,bottom);
        // ffill4(left+1,top+1,WHITE,0);
        
        delay(4);
        y++;
    }
    
    
 //    char nbscore[255];
    //  char* scoreLabel = "Score : ";
    // sprintf(nbscore,"%s%d", scoreLabel,score);
    setcolor(BLACK);
    char textWin[255];
    char* isWinLabel = "Anda ";
    char* isWin;
    if (win == 1) {
        isWin = "Menang!";
    } else {
        isWin = "Kalah!";
    }
    sprintf(textWin,"%s%s", isWinLabel,isWin);
     
     outtextxy((midx-40),(midy),textWin);
     // outtextxy((midx*3/4),midy,nbscore);
}