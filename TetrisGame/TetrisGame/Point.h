#ifndef __Point
#define __Point
#include "GotoXY.h"
#include <iostream>
#include <Windows.h>
using namespace std;

class Point {
	#define SQUARE (char) 254
	enum boreder {LENGTH = 10, HEIGHT = 15};

	int x;
	int y;
	int dirY = 1;
	int dirX = 0;

public:
	Point(int _x = 1, int _y = 1) {
		x = _x;
		y = _y;
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

	void draw() {
			gotoxy(x, y);
			cout << SQUARE;
	}

	void move() {
		y = (y + 1) % HEIGHT;
		gotoxy(x, y);
		cout << SQUARE;
		gotoxy(x, (y + HEIGHT - 1) % HEIGHT);
		cout << " ";
	 }
};


#endif // !__Point
