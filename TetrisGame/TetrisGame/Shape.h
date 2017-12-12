#ifndef __Shape
#define __Shape
#include "Point.h"
#include <conio.h>

class Shape {

	int type;
	Point shapeArr[4][4];

public:
	enum Shapes { line, square, bomb, joker };

	Shape(int _type) {
		type = _type;

		if (type == line) {
			shapeArr[3][0] = Point(5, 1, _SQUARE);
			shapeArr[3][1] = Point(6, 1, _SQUARE);
			shapeArr[3][2] = Point(7, 1, _SQUARE);
			shapeArr[3][3] = Point(8, 1, _SQUARE);
		}
		else if (type == square) {
			shapeArr[2][1] = Point(5, 0, _SQUARE);
			shapeArr[2][2] = Point(6, 0, _SQUARE);
			shapeArr[3][1] = Point(5, 1, _SQUARE);
			shapeArr[3][2] = Point(6, 1, _SQUARE);
		}
		else if (type == bomb) {
			shapeArr[3][1] = Point(6, 1, '@');
		}
		else if (type == joker) {
			shapeArr[3][1] = Point(6, 1, 'A');
		}
	}

	void draw() {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				if (shapeArr[i][j].getType() != ' ')
					shapeArr[i][j].draw();
		}
	}

	void gravity() {
		for (int k = 0; k < 14; k++) {
			for (int i = 3; i >= 0; i--) {
				for (int j = 0; j < 4; j++)
					shapeArr[i][j].moveDown();
			}
			Sleep(100);

			if (_kbhit()) {
				char keyPressed = _getch();
				move(keyPressed);
			}
		}
	}

	void move(char keyPressed) {

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				if (keyPressed == 'K') { //Left button
					shapeArr[i][j].moveLeft();
				}
				else if (keyPressed == 'M') { //Rigth button
					shapeArr[i][j].moveRight();
				}
		}
	}
};

#endif // !__Shape
