#include<iostream>
#include<graphics.h>
using namespace std;

int main(){
    int gd = DETECT, gm;


    initgraph(&gd, &gm,"");

    line(150, 150, 450, 150);
    line(1, 150, 450, 150);

    getch();
    closegraph();
}
