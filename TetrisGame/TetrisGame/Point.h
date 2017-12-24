#ifndef __Point
#define __Point
#include "GotoXY.h"
#include <iostream>
#include <Windows.h>
using namespace std;

#define _TOP_CUBE (char)223
#define _BOT_CUBE (char)220
#define _Long_CUBE (char)219

class Point {
	enum border { WIDTH = 10, HEIGHT = 15 };
	int x;
	int y;
	char type;

public:
	enum direction { DOWN, LEFT, RIGHT };

	Point(int _x = 0, int _y = 0, char _type = ' ') {
		x = _x;
		y = _y;
		type = _type;
	}
		int  getX() {return x;}
	int getY() {return y;}
	void setX(int _x) {x = _x;}
	void setY(int _y) {y = _y;}
	char getType() {return type;}
	void setType(char _type) {type = _type;}
	void movePoint(int _x, int _y);
	void draw();
	void move(int dir, bool gameBaord[][12]);
	bool canMove(int dir, bool gameBaord[][12]);



};


#endif // !__Point
