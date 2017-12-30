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
void Point::move(int dir, char gameBaord[][11]) {

	if (type != ' ') {
		if (dir == DOWN) {
			gotoxy(x, y);

			if (type == Point::Joker)
				cout << gameBaord[y][x];
			else
				cout << ' ';

			y++;
			draw();
		}

		else if (dir == LEFT) {
			gotoxy(x, y);

			if (type == Point::Joker)
				cout << gameBaord[y][x];
			else
				cout << ' ';

			x--;
			draw();
		}

		else if (dir == RIGHT) {
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


	if (dir == DOWN && y + 1 < HEIGHT) {//Move the point down
		if (gameBaord[y + 1][x] == ' ') //that's mean that we can move the point down by 1.
			return true;
		else
			if (type == Point::Joker)
				return true;
	}

	else if (dir == LEFT && x > 1) {
		if (gameBaord[y][x - 1] == ' ') //check that we can move left.
			return true;
		else
			if (type == Point::Joker)
				return true;
	}

	else if (dir == RIGHT && x < WIDTH) {
		if (gameBaord[y][x + 1] == ' ')
			return true;
		else
			if (type == Point::Joker)
				return true;
	}

	return false;
}