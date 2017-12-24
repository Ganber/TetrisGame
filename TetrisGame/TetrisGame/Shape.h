#ifndef __Shape
#define __Shape
#include "Point.h"
#include <conio.h>

#define SPC (char) 32

class Shape {
	enum colors
	{
		Black, Blue, Green, Cyan, Red, Magenta, Brown,
		Light_Gray, Dark_Gray, Light_Blue, Light_Green,
		Light_Cyan, Light_Red, LightMagenta, Yellow, White
	};
	enum border { WIDTH = 10, HEIGHT = 15 };

	bool isRotate;
	int type;
	int color;
	int *gravitySpeed;
	Point shapeArr[4]; //For all kind of shapes

public:
	enum Shapes { line, cube, bomb, joker };

	Shape(int _type, int* _gravitySpeed) {

		type = _type;
		gravitySpeed = _gravitySpeed;
		isRotate = false;

		if (type == line) {
			color = Light_Red;
			shapeArr[0] = Point(5, 0, 'o');
			shapeArr[1] = Point(6, 0, 'o');
			shapeArr[2] = Point(7, 0, 'o');
			shapeArr[3] = Point(8, 0, 'o');
		}
		else if (type == cube) {
			color = White;
			shapeArr[0] = Point(5, 1, 'o');
			shapeArr[1] = Point(6, 1, 'o');
			shapeArr[2] = Point(5, 0, 'o');
			shapeArr[3] = Point(6, 0, 'o');
		}
		else if (type == bomb) {
			color = Cyan;
			shapeArr[0] = Point(6, 1, '@');
		}
		else if (type == joker) {
			color = Brown;
			shapeArr[0] = Point(6, 1, 'A');
		}
	}

	void draw() {
		SetColor(color);
		for (int i = 0; i < 4; i++) {
			if (shapeArr[i].getType() != ' ')
				shapeArr[i].draw();
		}
	}

	int gravity(bool GameBoard[][HEIGHT - 3])
	{
		int tempGravity = *gravitySpeed;
		bool gravityChanged = false;
		char keyPressed = 0;
		while (shapeArr[0].getY() < HEIGHT + 1 && isShapeCanMove(Point::DOWN, GameBoard)) {

			for (int i = 0; i < 4; i++) {
				if (shapeArr[i].getType() != ' ')
					shapeArr[i].move(Point::DOWN, GameBoard);
			}

			while (_kbhit() ) {
				keyPressed = _getch();

				if (keyPressed == '9')
					return 9;

				else if (keyPressed == '2') {
					gotoxy(2, HEIGHT + 3);
					cout << "Game Paused" << endl;
					keyPressed = _getch();
					while (keyPressed != '2') {
						keyPressed = _getch();
					}
					gotoxy(2, HEIGHT + 3);
					cout << "              " << endl;
				}

				else if (keyPressed == '3')
					*gravitySpeed = *gravitySpeed + 100;

				else if (keyPressed == '4')
					*gravitySpeed = *gravitySpeed - 100;

				else if (keyPressed == SPC && type == line)
					rotate();
				else
					move(keyPressed, GameBoard);

				if (keyPressed == 's' && gravityChanged==false) {
					tempGravity = *gravitySpeed;
					*gravitySpeed = 30;
					gravityChanged = true;
				}

			}

			Sleep(*gravitySpeed);
		}

		if (gravityChanged)
			*gravitySpeed = tempGravity;


		for (int i = 0; i < 4; i++) //set the map array of the game 
			GameBoard[shapeArr[i].getY()][shapeArr[i].getX()] = true;
	}

	void move(char keyPressed, bool GameBoard[][12]) {

		if (keyPressed == 'a') {
			if (isShapeCanMove(Point::LEFT, GameBoard))
				for (int i = 0; i < 4; i++)
					shapeArr[i].move(Point::LEFT, GameBoard);
		}

		if (keyPressed == 'd') {
			if (isShapeCanMove(Point::RIGHT, GameBoard))
				for (int i = 0; i < 4; i++)
					shapeArr[3 - i].move(Point::RIGHT, GameBoard);
		}

	}

	void rotate() {

		if (shapeArr[3].getX() > WIDTH - 2 && isRotate) {
			for (int i = 0; i < 4; i++)
				shapeArr[i].movePoint(shapeArr[i].getX() - (WIDTH + 4 - shapeArr[i].getX()), shapeArr[i].getY());
		}

		for (int i = 0; i < 4; i++)

			if (!isRotate) {
				int newX = shapeArr[i].getX() - i;
				int newY = shapeArr[i].getY() - i;
				shapeArr[i].movePoint(newX, newY);
			}
			else {
				int newX = shapeArr[i].getX() + i;
				int newY = shapeArr[i].getY() + i;
				shapeArr[i].movePoint(newX, newY);
			}

			isRotate = !isRotate;
	}

	bool isShapeCanMove(int dir, bool gameBaord[][12]) {
		bool res = true;

		for (int i = 0; i < 4; i++)
			if (shapeArr[i].canMove(dir, gameBaord) == false && shapeArr[i].getType() != ' ')
				res = false;

		return res;
	}
};

#endif // !__Shape
