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
	enum direction { DOWN, LEFT, RIGHT }; //TODO: this is here and also in shape.h ??
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

	void move(int dir, bool gameBaord[][12]) {

		if (dir == DOWN) {//Move the point down
			if (gameBaord[y + 1][x] == false) { //that's mean that we can move the point down by 1.
				gotoxy(x, y++); //change the y value after we finish the statment.
				cout << ' ';
				draw();
			}
		}

		else if (dir == LEFT) {
			if (x > 1 && gameBaord[y][x - 1] == false) { //check that we can move left.
				gotoxy(x--, y); //chagne the x value to x-1. (moving left)
				cout << ' ';
				draw();
			}

		}

		else if (dir == RIGHT) {
			if (x <= WIDTH && gameBaord[y][x + 1] == false) {
				gotoxy(x++, y);//chagne the x value to x+1. (moving right)
				cout << ' ';
				draw();
			}

		}

	}

	bool canMove(int dir, bool gameBaord[][12]) {

		if (dir == DOWN) {//Move the point down
			if (gameBaord[y + 1][x] == false) { //that's mean that we can move the point down by 1.
				return true;
			}
			else
				return false;
		}

		else if (dir == LEFT) {
			if (x > 1 && gameBaord[y][x - 1] == false) { //check that we can move left.
				return true;
			}
			else //that's mean we cant move the point left.
				return false;
		}

		else if (dir == RIGHT) {
			if (x <= WIDTH && gameBaord[y][x + 1] == false) {
				return true;
			}
			else
				return false;
		}

		return false;
	}

};


#endif // !__Point
