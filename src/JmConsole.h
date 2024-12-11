#pragma once

void gotoxy(int x, int y);

void Deftam(int x, int y);

void logC();

struct point{
	int x;
	int y;
};

void inicialize(char c);

void drawPoint(int x, int y, int color, char c);
void drawPointP(struct point p, int color, char c);

void drawLine(struct point p1, struct point p2, char c, char c2, int color);

void drawTriangle(struct point p1, struct point p2, struct point p3, int col, char c);

