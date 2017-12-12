#ifndef __Point
#define __Point
#include "GotoXY.h"
#include <iostream>
#include <Windows.h>
using namespace std;

class Point {
	#define _SQUARE '*'
	enum border {WIDTH = 10, HEIGHT = 15};

	int x;
	int y;
	char type;

public:
	Point(int _x = 0, int _y = 0, char _type = ' ') {
		x = _x;
		y = _y;
		type = _type;
	}

	int  getX() {
		return x;
	}

	int getY() {
		return y;
	}

	void setX(int _x) {
		x = _x;
	}

	void setY(int _y) {
		y = _y;
	}

	char getType() {
		return type;
	}

	void draw() {
			gotoxy(x, y);
			cout << type;
	}

	void moveDown() {
		//Move the point down
		gotoxy(x,y+1); 
		cout << type;
		gotoxy(x, y);
		cout << ' ';
		y++;
	 }

	void moveRight() {
		if (x <= WIDTH) {
			gotoxy(x + 1, y);
			cout << type;
			gotoxy(x, y);
			cout << ' ';
			x++;
		}
	}

	void moveLeft() {
		if (x >= 0) {
			gotoxy(x - 1, y);
			cout << type;
			gotoxy(x, y);
			cout << ' ';
			x--;
		}
	}
};


#endif // !__Point
