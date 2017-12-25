#include "Point.h"


void Point::movePoint(int _x, int _y) {
	type = ' ';
	draw();
	x = _x;
	y = _y;
	type = 'o';
	draw();
}
void Point::draw() {
	if (y > -1) {
		gotoxy(x, y);
		cout << type;
	}
}
void Point::move(int dir) {
	if (type != ' ') {
		if (dir == DOWN) {
			gotoxy(x, y++); //change the y value after we finish the statment.
			cout << ' ';
			draw();
		}

		else if (dir == LEFT) {
			gotoxy(x--, y); //chagne the x value to x-1. (moving left)
			cout << ' ';
			draw();
		}

		else if (dir == RIGHT) {
			gotoxy(x++, y);//chagne the x value to x+1. (moving right)
			cout << ' ';
			draw();
		}
	}
}
bool Point::canMove(int dir, char gameBaord[][11]) {

	if (y<HEIGHT-1 && dir == DOWN) {//Move the point down
		if (gameBaord[y + 1][x] == ' ') { //that's mean that we can move the point down by 1.
			return true;
		}
	}

	else if (dir == LEFT) {
		if (x > 1 && gameBaord[y][x - 1] == ' ') { //check that we can move left.
			return true;
		}
	}

	else if (dir == RIGHT) {
		if (x < WIDTH && gameBaord[y][x + 1] == ' ') {
			return true;
		}
	}

	return false;
}