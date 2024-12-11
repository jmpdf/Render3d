#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


/* TODO (#1#): adicionar funcoes no header */

/* TODO (#1#): ler ascii de arquivo em txt
 */



//possui um sistema de ids que atualmente é completamente controlado pelo usuario em breve esse sistema vai parrar a ser controlado pela bilblioteca
//          Y   X   

#include "JmConsole.h"



int tamX = 220;
int tamY = 50;

int log_p = 0;

int debugMode = 0;
int desenMode = 0;
int callnum = 0;



void gotoxy(int x, int y){
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void logC(){
	gotoxy(10,100+log_p);
	printf("%i : ", log_p);
	log_p++;
}
void colorchange(int col){
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, col);
}

void Deftam(int x, int y){
	tamX = x;
	tamY = y;
}

void start(char c){
	ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);
	int i = 0;
	int j = 0;
	for(j = 0; j < tamY; j++){
		for(i = 0; i < tamX; i++){
			printf("%c",c);
		}
		printf("\n");
	}
}

struct point toPoint(int x, int y){
	struct point a = {.x = x, .y = y};
	return a;
}


void drawPoint(int x, int y, int color, char c){
	if(x >= 0 && x < tamX && y > 0 && y <= tamY){
		if(desenMode == 1){
			callnum++;
			gotoxy(0,1);
			printf("%i", callnum);
		}
		gotoxy(x,tamY-y);
		colorchange(color);
		printf("%c", c);
	}else if(debugMode == 1){
		logC();
		printf("drawed pixel out of range");
	}
}

void drawPointP(struct point p, int color, char c){
	drawPoint(p.x,p.y,color,c);
}

void drawLine(struct point p1, struct point p2, char c, char c2, int color){
	float dx = p2.x - p1.x;
	float dy = p2.y - p1.y;
	int ax = p1.x;
	int ay = p1.y;
	
	if(p1.x > p2.x){
		ax = p2.x;
		ay = p2.y;
		dx = p1.x - p2.x;
		dy = p1.y - p2.y;
	}
	
	if(abs(dx) >= abs(dy)){
		int x;
		for(x = dx/abs(dx); x != dx && dx != 0; x+= dx/abs(dx)){
			float y;
			float ratx = dx/x;
			y = dy/ratx;
			drawPoint(round(x)+ax, round(y)+ay,color,c);
			if(debugMode == 1){
				logC();
				printf("p1.x = %i p2.x = %i p1.y = %i p2.y = %i use 1 x = %i dx = %f dy = %f ratx = %f y = %f",p1.x,p2.x,p1.y,p2.y,x,dx,dy,ratx,y);
			}
		}	
	}else{
		int y;
		for(y = dy/abs(dy); y != dy && dy != 0 ; y+= dy/abs(dy)){
			float x;
			float raty = dy/y;
			x = dx/raty;
			drawPoint(round(x)+ax, round(y)+ay,color,c);
			if(debugMode == 1){
				logC();
				printf("p1.x = %i p2.x = %i p1.y = %i p2.y = %i use 2 y = %i dx = %f dy = %f ratx = %f x = %f",p1.x,p2.x,p1.y,p2.y,y,dx,dy,raty,x);
			}
		}
		
	}
	drawPoint(p1.x,p1.y,color,c2);
	drawPoint(p2.x,p2.y,color,c2);
}


void simplepoint(int x, int y, int col){
	drawPoint(x,y,col,'X');
}

void drawSimpleLine(struct point p1, struct point p2, int col){
	
	drawLine(p1,p2,'X','O',col);
	
}

void drawTriangle(struct point p1, struct point p2, struct point p3, int col, char c){
	drawLine(p1,p2,c,c,col);
	drawLine(p2,p3,c,c,col);
	drawLine(p3,p1,c,c,col);
}
void anim(){
	int x = 5;
	int y = 15;
	int z = 50;
	int col = 11;
	//p
	
	drawSimpleLine(toPoint(z +1*x,7*x),toPoint(z+1*x,9*x),col);
	drawSimpleLine(toPoint(z +1*x,9*x),toPoint(z+2*x,9*x),col);
	drawSimpleLine(toPoint(z +2*x,9*x),toPoint(z+2*x,8*x),col);
	drawSimpleLine(toPoint(z +2*x,8*x),toPoint(z+1*x,8*x),col);
	
	//o
	drawSimpleLine(toPoint(z +3*x,7*x),toPoint(z+3*x,9*x),col);
	drawSimpleLine(toPoint(z +3*x,9*x),toPoint(z+4*x,9*x),col);
	drawSimpleLine(toPoint(z +4*x,9*x),toPoint(z+4*x,7*x),col);
	drawSimpleLine(toPoint(z +4*x,7*x),toPoint(z+3*x,7*x),col);
	
	//w
	drawSimpleLine(toPoint(z +5*x,7*x),toPoint(z+5*x,9*x),col);
	drawSimpleLine(toPoint(z +5*x,7*x),toPoint(z+6*x,8*x),col);
	drawSimpleLine(toPoint(z +6*x,8*x),toPoint(z+7*x,7*x),col);
	drawSimpleLine(toPoint(z +7*x,7*x),toPoint(z+7*x,9*x),col);
	
	//e
	drawSimpleLine(toPoint(z +8*x,7*x),toPoint(z+8*x,9*x),col);
	drawSimpleLine(toPoint(z +8*x,7*x),toPoint(z+9*x,7*x),col);
	drawSimpleLine(toPoint(z +8*x,8*x),toPoint(z+9*x,8*x),col);
	drawSimpleLine(toPoint(z +8*x,9*x),toPoint(z+9*x,9*x),col);
	
	//r
	drawSimpleLine(toPoint(z +10*x,7*x),toPoint(z+10*x,9*x),col);
	drawSimpleLine(toPoint(z +10*x,9*x),toPoint(z+11*x,9*x),col);
	drawSimpleLine(toPoint(z +11*x,9*x),toPoint(z+11*x,8*x),col);
	drawSimpleLine(toPoint(z +10*x,8*x),toPoint(z+11*x,7*x),col);
	drawSimpleLine(toPoint(z +11*x,8*x),toPoint(z+10*x,8*x),col);
	
	//e
	drawSimpleLine(toPoint(z +12*x,7*x),toPoint(z+12*x,9*x),col);
	drawSimpleLine(toPoint(z +12*x,7*x),toPoint(z+13*x,7*x),col);
	drawSimpleLine(toPoint(z +12*x,8*x),toPoint(z+13*x,8*x),col);
	drawSimpleLine(toPoint(z +12*x,9*x),toPoint(z+13*x,9*x),col);
	
	//d
	drawSimpleLine(toPoint(z +14*x,7*x),toPoint(z+14*x,9*x),col);
	drawSimpleLine(toPoint(z +14*x,9*x),toPoint(z+15*x,8*x),col);
	drawSimpleLine(toPoint(z +15*x,8*x),toPoint(z+14*x,7*x),col);

	
	//b
	drawSimpleLine(toPoint(z +7*x,4*x),toPoint(z+7*x,6*x),col);
	drawSimpleLine(toPoint(z +7*x,6*x),toPoint(z+8*x,6*x),col);
	drawSimpleLine(toPoint(z +8*x,6*x),toPoint(z+7*x,5*x),col);
	drawSimpleLine(toPoint(z +7*x,5*x),toPoint(z+8*x,4*x),col);
	drawSimpleLine(toPoint(z +8*x,4*x),toPoint(z+7*x,4*x),col);
	
	//y
	drawSimpleLine(toPoint(z +9*x,4*x),toPoint(z+9*x,6*x),col);
	drawSimpleLine(toPoint(z +9*x,5*x),toPoint(z+10*x,6*x),col);
	
	//j
	drawSimpleLine(toPoint(z +1*x,1*x),toPoint(z+2*x,1*x),col);
	drawSimpleLine(toPoint(z +2*x,1*x),toPoint(z+2*x,4*x),col);
	drawSimpleLine(toPoint(z +0*x,4*x),toPoint(z+4*x,4*x),col);
	
	//m
	drawSimpleLine(toPoint(z +3*x,1*x),toPoint(z+3*x,3*x),col);
	drawSimpleLine(toPoint(z +3*x,3*x),toPoint(z+4*x,2*x),col);
	drawSimpleLine(toPoint(z +4*x,2*x),toPoint(z+5*x,3*x),col);
	drawSimpleLine(toPoint(z +5*x,3*x),toPoint(z+5*x,1*x),col);
	
	//c
	drawSimpleLine(toPoint(z + y +3*x,1*x),toPoint(z + y+3*x,3*x),col);
	drawSimpleLine(toPoint(z + y +3*x,1*x),toPoint(z + y+4*x,1*x),col);
	drawSimpleLine(toPoint(z + y +3*x,3*x),toPoint(z + y+4*x,3*x),col);
	
	//o
	drawSimpleLine(toPoint(z + y +5*x,1*x),toPoint(z + y+5*x,3*x),col);
	drawSimpleLine(toPoint(z + y +5*x,3*x),toPoint(z + y+6*x,3*x),col);
	drawSimpleLine(toPoint(z + y +6*x,3*x),toPoint(z + y+6*x,1*x),col);
	drawSimpleLine(toPoint(z + y +6*x,1*x),toPoint(z + y+5*x,1*x),col);
	
	//n
	drawSimpleLine(toPoint(z + y +7*x,1*x),toPoint(z + y+7*x,3*x),col);
	drawSimpleLine(toPoint(z + y +7*x,3*x),toPoint(z + y+8*x,1*x),col);
	drawSimpleLine(toPoint(z + y +8*x,1*x),toPoint(z + y+8*x,3*x),col);
	
	//s
	drawSimpleLine(toPoint(z + y +9*x,1*x),toPoint(z + y+10*x,1*x),col);
	drawSimpleLine(toPoint(z + y +10*x,1*x),toPoint(z + y+10*x,2*x),col);
	drawSimpleLine(toPoint(z + y +10*x,2*x),toPoint(z + y+9*x,2*x),col);
	drawSimpleLine(toPoint(z + y +9*x,2*x),toPoint(z + y+9*x,3*x),col);
	drawSimpleLine(toPoint(z + y +9*x,3*x),toPoint(z + y+10*x,3*x),col);
	
	//o
	drawSimpleLine(toPoint(z + y +11*x,1*x),toPoint(z + y+11*x,3*x),col);
	drawSimpleLine(toPoint(z + y +11*x,3*x),toPoint(z + y+12*x,3*x),col);
	drawSimpleLine(toPoint(z + y +12*x,3*x),toPoint(z + y+12*x,1*x),col);
	drawSimpleLine(toPoint(z + y +12*x,1*x),toPoint(z + y+11*x,1*x),col);
	
	//l
	drawSimpleLine(toPoint(z + y +13*x,3*x),toPoint(z + y+13*x,1*x),col);
	drawSimpleLine(toPoint(z + y +13*x,1*x),toPoint(z + y+14*x,1*x),col);
	
	//e
	drawSimpleLine(toPoint(z + y +15*x,1*x),toPoint(z + y+15*x,3*x),col);
	drawSimpleLine(toPoint(z + y +15*x,1*x),toPoint(z + y+16*x,1*x),col);
	drawSimpleLine(toPoint(z + y +15*x,2*x),toPoint(z + y+16*x,2*x),col);
	drawSimpleLine(toPoint(z + y +15*x,3*x),toPoint(z + y+16*x,3*x),col);
	
}

void inicialize(char c){
	start(c);
	anim();
	sleep(3);
	int i;
	int j;
	for(j = 1; j <= tamY; j++){
		for(i = 0; i < tamX; i++){
			drawPoint(i,j,7,' ');
		}
	}
	
}


