#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <windows.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include "JmConsole.h"


struct point3d{
	float x;
	float y;
	float z;
};

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

struct point3d rotate(struct point3d p1, struct point3d Orig, int angleD, int eixo){
	
	//eixo 1 = x
	//eixo 2 = y
	//eixo 3 = z
	
	
	struct point3d Rp;
	
	float x = p1.x - Orig.x;
	float y = p1.y - Orig.y;
	float z = p1.z - Orig.z;
	
	float angle = angleD /(180/3.14159265358979);

	//logC();
	//printf("%f : %f : %f",sin(angle),cos(angle),z);
	float dx;
	float dy;
	float dz;
	if(eixo == 1){
		dx = x;
		dy = y*cos(angle) - z*sin(angle);
		dz = y*sin(angle) + z*cos(angle);
	}
	else if(eixo == 2){
		dx = x*cos(angle) + z*sin(angle);
		dy = y;
		dz = x*(0-sin(angle)) + z*cos(angle);
		
	}else if(eixo == 3){
		dx = x*cos(angle) - y*sin(angle);
		dy = x*sin(angle) + y*cos(angle);
		dz = z;
	}
	
	//logC();
	//printf("%f : %f : %f",dx,dy,dz);
	
	Rp.x = dx + Orig.x;
	Rp.y = dy + Orig.y;
	Rp.z = dz + Orig.z;
	
	return Rp;
}

struct point display(struct point3d cam, struct point3d b){
	float x = b.x - cam.x;
	float y = b.y - cam.y;
	float z = b.z - cam.z;
	
	struct point3d e = {
		.x = 0,
		.y = 0,
		.z = 220
	};
	if(z == 0){
		z = 1;
	}
	
	
	struct point a = {
		.x = 110 + (e.z/z)*x + e.x,
		.y = 25 +  (e.z/z)*y + e.y
	};
	
	return a;
	
}
	struct point3d camerapos = {.x = 0, .y = 17, .z = -60};

	struct point3d p1 = {.x = -10, .y = 10, .z = 30};
	struct point3d p2 = {.x = -10, .y = 10, .z = 10};
	struct point3d p3 = {.x = 10, .y = 10, .z = 30};
	struct point3d p4 = {.x = 10, .y = 10, .z = 10};
	struct point3d p5 = {.x = -10, .y = 20, .z = 30};
	struct point3d p6 = {.x = -10, .y = 20, .z = 10};
	struct point3d p7 = {.x = 10, .y = 20, .z = 30};
	struct point3d p8 = {.x = 10, .y = 20, .z = 10};
	struct point3d pcenter = {.x = 0, .y = 15, .z = 20};
	
	struct point pp1;
	struct point pp2;
	struct point pp3;
	struct point pp4;
	struct point pp5;
	struct point pp6;
	struct point pp7;
	struct point pp8;



void eraseform(){
	drawLine(pp1,pp2,' ',' ',3);
	drawLine(pp2,pp4,' ',' ',3);
	drawLine(pp4,pp3,' ',' ',3);
	drawLine(pp3,pp1,' ',' ',3);
		
	drawLine(pp5,pp1,' ',' ',4);
	drawLine(pp6,pp2,' ',' ',4);
	drawLine(pp7,pp3,' ',' ',4);
	drawLine(pp8,pp4,' ',' ',4);
		
	drawLine(pp5,pp6,' ',' ',5);
	drawLine(pp6,pp8,' ',' ',5);
	drawLine(pp8,pp7,' ',' ',5);
	drawLine(pp7,pp5,' ',' ',5);
}
void rotateform(int i){
	p1 = rotate(p1,pcenter,10,i);
	p2 = rotate(p2,pcenter,10,i);
	p3 = rotate(p3,pcenter,10,i);
	p4 = rotate(p4,pcenter,10,i);
	p5 = rotate(p5,pcenter,10,i);
	p6 = rotate(p6,pcenter,10,i);
	p7 = rotate(p7,pcenter,10,i);
	p8 = rotate(p8,pcenter,10,i);
		
}

int main(int argc, char *argv[]) {

	
	int tamX = 220;
	int tamY = 50;
	
	Deftam(tamX,tamY);
	inicialize(' ');
	
	hidecursor();
	
	int rotatex = 0;
	int rotatey = 0;
	
	
	while(1==1){
	
		pp1 = display(camerapos,rotate(p1,camerapos,(0-rotatey),2)); 
		pp2 = display(camerapos,rotate(p2,camerapos,(0-rotatey),2)); 
		pp3 = display(camerapos,rotate(p3,camerapos,(0-rotatey),2)); 
		pp4 = display(camerapos,rotate(p4,camerapos,(0-rotatey),2)); 
		pp5 = display(camerapos,rotate(p5,camerapos,(0-rotatey),2)); 
		pp6 = display(camerapos,rotate(p6,camerapos,(0-rotatey),2)); 
		pp7 = display(camerapos,rotate(p7,camerapos,(0-rotatey),2)); 
		pp8 = display(camerapos,rotate(p8,camerapos,(0-rotatey),2)); 
		
		drawLine(pp1,pp2,'x','o',3);
		drawLine(pp2,pp4,'x','o',3);
		drawLine(pp4,pp3,'x','o',3);
		drawLine(pp3,pp1,'x','o',3);
		
		drawLine(pp5,pp1,'x','o',4);
		drawLine(pp6,pp2,'x','o',4);
		drawLine(pp7,pp3,'x','o',4);
		drawLine(pp8,pp4,'x','o',4);
		
		drawLine(pp5,pp6,'x','o',5);
		drawLine(pp6,pp8,'x','o',5);
		drawLine(pp8,pp7,'x','o',5);
		drawLine(pp7,pp5,'x','o',5);
		
		gotoxy(0,0);
		printf("x: %f, y: %f, z: %f",camerapos.x,camerapos.y,camerapos.z);
		
		char a = getchar();
		if(a == 'a'){
			camerapos.x-=0.4;
			eraseform();
		}else if(a == 'w'){
			camerapos.y+=.4;
			eraseform();
			
		}else if(a == 'd'){
			camerapos.x+=.4;
			eraseform();
			
		}else if(a == 's'){
			camerapos.y-=.4;
			eraseform();
			
		}else if(a == 'l'){
			eraseform();
			rotateform(1);
					
		}else if(a == 'k'){
			eraseform();
			rotateform(2);		
		}else if(a == 'j'){
			eraseform();
			rotateform(3);		
		}else if(a == 'o'){
			camerapos.z--;
			eraseform();
		
		}else if(a == 'p'){
			camerapos.z++;
			eraseform();
	
		}else if(a == '-'){
			rotatey++;
			eraseform();
		}else if(a == '+'){
			rotatey--;
			eraseform();
		}
	}
	
	return 0;
}
