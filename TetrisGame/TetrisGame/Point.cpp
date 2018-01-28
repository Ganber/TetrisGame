#include "Point.h"
#include "Shape.h"

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
void Point::draw(char val)
{
	if (y > -1) {
		gotoxy(x, y);
		cout << val;
	}
}
void Point::move(int dir, char gameBaord[][11]) {

	if (type != ' ') {
		if (dir == Down) {
			gotoxy(x, y);

			if (type == Point::Joker)
				cout << gameBaord[y][x];
			else
				cout << ' ';

			y++;
			draw();
		}

		else if (dir == leftArrow) {
			gotoxy(x, y);

			if (type == Point::Joker)
				cout << gameBaord[y][x];
			else
				cout << ' ';

			x--;
			draw();
		}

		else if (dir == rightArrow) {
			gotoxy(x, y);
			if (type == Point::Joker)
				cout << gameBaord[y][x];
			else
				cout << ' ';

			x++;
			draw();
		}
	}
}
bool Point::canMove(int dir, char gameBaord[][11]) {


	if (dir == Down && y + 1 < HEIGHT) {//Move the point down
		if (gameBaord[y + 1][x] == ' ') //that's mean that we can move the point down by 1.
			return true;
		else
			if (type == Point::Joker)
				return true;
	}

	else if (dir == leftArrow && x > 1) {
		if (gameBaord[y][x - 1] == ' ') //check that we can move left.
			return true;
		else
			if (type == Point::Joker)
				return true;
	}

	else if (dir == rightArrow && x < WIDTH) {
		if (gameBaord[y][x + 1] == ' ')
			return true;
		else
			if (type == Point::Joker)
				return true;
	}

	return false;
}

void Point::setXY(int newX, int newY)
{
	x = newX;
	y = newY;
}
