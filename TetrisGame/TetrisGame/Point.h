#ifndef __Point
#define __Point
#include "GotoXY.h"
#include <iostream>
using namespace std;



class Point {
	enum border { WIDTH = 10, HEIGHT = 15 };
	int x;
	int y;
	char type;

public:
	enum direction { leftArrow = 75, rightArrow = 77, Down = 80 };
	enum Type {RegularShape='O',Bomb='@',Joker='A',EmptyType=' '};

	Point(int _x = 0, int _y = 0, char _type = EmptyType) {
		x = _x;
		y = _y;
		type = _type;
	}
		int  getX()const {return x;}
	int getY()const {return y;}
	void setX(int _x) {x = _x;}
	void setY(int _y) {y = _y;}
	char getType()const {return type;}
	void setType(char _type) {type = _type;}
	void movePoint(int _x, int _y);
	void draw();
	void draw(char val);
	void move(int dir, char gameBaord[][WIDTH +1]);
	bool canMove(int dir, char gameBaord[][WIDTH +1]);
	void setXY(int newX, int newY);

};


#endif // !__Point
