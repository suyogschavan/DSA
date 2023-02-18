#include<iostream>
#include<graphics.h>
using namespace std;

static int LEFT=1, RIGHT=2, BOTTOM=4, TOP=8, xmin, ymin, xmax, ymax;
int getcode(int x, int y){  // coordinates of line // getcode returns the code of endpoints code means the regian code i.e TBRL
	int code = 0;
	if(y>ymax) code|=TOP;   // if condition satisfies, code will be set to TOP
	if(y<ymin) code|=BOTTOM;
	if(x<xmin) code|=LEFT;
	if(x>xmax) code|=RIGHT;
	return code;
}

int main(){
	
	int gd=DETECT, gm;
	initgraph(&gd, &gm, "");
	setcolor(WHITE);
	cout<<"Enter windows minimum and maximum values: ";
	cout<<"\nEnter the xmin: ";
	cin>>xmin;
	cout<<"\nEnter the ymin: ";
	cin>>ymin;
	cout<<"\nEnter the xmax: ";
	cin>>xmax;
	cout<<"\nEnter the ymax: ";
	cin>>ymax;
	rectangle(xmin, ymin, xmax, ymax);
	int x1, y1, x2, y2;
	cout<<"Enter the endpoints of the line: ";
	cout<<"\nEnter the x1 and y1: ";
	cin>>x1>>y1;
	cout<<"\nEnter the x2 and y2: ";
	cin>>x2>>y2;
	line(x1, y1, x2, y2);
	getch();
	int outcode1=getcode(x1, y1), outcode2=getcode(x2, y2);
	int accept=0;
	while(1){
		float m=(float)(y2-y1)/(x2-x1); // formula of slope y2-y2/x2-x1
		if(outcode1==0 && outcode2==0){   // conditional operator &&
			accept=1;
			break;
		}
		else if((outcode1 & outcode2)!=0){  // here we are doing bitwize and
			break;
		}
		else{
			int x, y;
			int temp;
			if(outcode1==0)
				temp=outcode2;
			else
				temp = outcode1;
			if(temp & TOP)
				{
					x=x1+(ymax-y1)/m;
					y=ymax;
				}
			else if(temp & BOTTOM){
				x=x1+(ymin-y1)/m;
				y=ymin;
			}
			else if(temp & LEFT){
				x=xmin;
				y = y1+m*(xmin-x1);
			}
			else if(temp & RIGHT){
				x=xmax;
				y=y1+m*(xmax-x1);
			}
			
			if(temp==outcode1){
				x1=x;
				y1=y;
				outcode1=getcode(x1, y1);
			}
			else{
				x2=x;
				y2=y;
				outcode2=getcode(x2, y2);
			}
			
			}
		}
		
		cout<<"after clipping";
		if(accept)
			cleardevice();
			rectangle(xmin, ymin, xmax, ymax);
			setcolor(RED);
			line(x1, y1, x2, y2);
			getch();
			closegraph();
	
	
	return 0;
}