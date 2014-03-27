#include <graphics.h>
#include <process.h>
#include <dos.h>
#include <conio.h>
#include "car.h"
#include <stdio.h>
#include <math.h>


int main() {
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
    int ch; 
    int p = 60;
    int l = 60;
    int xc = getmaxx() / 2;
    int yc = getmaxy() - 60;
    
    Car cars(xc,yc,p,l);
    


    while(1) {                                                              //infinite loop              
       cars.draw();
       // outtextxy(400,400,"Press Esc to Exit.....");
        if(kbhit())                                            //check if a key is pressed
        {
            ch=getch();

            if(ch==75)      //move left
            {
                cars.moveLeft();

            }

            if(ch==77)      //move right
            {
                cars.moveRight();
            }


            if(ch==27)     //exit when esc pressed
                break;


        delay(5);
        cleardevice();
        }
                    
    }

    return 0;
}