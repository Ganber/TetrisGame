#ifndef __Point
#define __Point
#include "GotoXY.h"
#include "Game.h"
#include <iostream>
#include <Windows.h>
using namespace std;

class Point {
	#define _TOP_CUBE (char)223
	#define _BOT_CUBE (char)220
	#define _Long_CUBE (char)219

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

	void setType(char _type) {
		type = _type;
	}

	void movePoint(int _x, int _y) {
		type = ' ';
		draw();
		x = _x;
		y = _y;
		type = 'o';
		draw();
	}

	void draw() {
		if (y > -1) {
			gotoxy(x, y);
			cout << type;
		}
	}

	void moveDown() {
		//Move the point down
		if (y > -1) {
			gotoxy(x, y + 1);
			cout << type;
			gotoxy(x, y);
			cout << ' ';
		}
			y++;
	 }

	bool moveRight() {
		if (x <= WIDTH) {
			gotoxy(x + 1, y);
			cout << type;
			gotoxy(x, y);
			cout << ' ';
			x++;
			return true;
		}
		else
			return false;
	}

	bool moveLeft() {
		if (x > 1) {
			gotoxy(x - 1, y);
			cout << type;
			gotoxy(x, y);
			cout << ' ';
			x--;
			return true;
		}
		else
			return false;
	}
};


#endif // !__Point
