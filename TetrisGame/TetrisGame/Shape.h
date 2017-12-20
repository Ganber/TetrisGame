#ifndef __Shape
#define __Shape
#include "Point.h"
#include "Game.h"
#include <conio.h>

#define SPC (char) 32

class Shape {
	enum colors 
	{Black,Blue,Green,Cyan,Red,Magenta,Brown,
	 Light_Gray,Dark_Gray,Light_Blue,Light_Green,
	 Light_Cyan,Light_Red,LightMagenta,Yellow,White};
	


	bool isRotate;
	int type;
	int color;
	int gravitySpeed;
	Point shapeArr[4]; //For all kind of shapes

public:
	enum Shapes { line, cube, bomb, joker };
	enum direction { DOWN, LEFT, RIGHT };

	Shape(int _type) {

		type = _type;
		gravitySpeed = 500;
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

	void gravity(bool GameBoard[][12]) //TODO: change 12 to height
	{

		while (shapeArr[0].getY() < HEIGHT + 1 && isShapeCanMove(DOWN, GameBoard)) {	//TODO: hit other shape

			for (int i = 0; i < 4; i++) {
				if (shapeArr[i].getType() != ' ')
					shapeArr[i].move(DOWN, GameBoard);
			}

			while (_kbhit()) {
				char keyPressed = _getch();
				if (keyPressed == SPC && type == line)
					rotate();
				else
					move(keyPressed, GameBoard);

				Sleep(50); //TODO: NEED A FIX FOR FAST MOVING
			}

			Sleep(gravitySpeed);
		}

		for (int i = 0; i < 4; i++) //set the map array of the game 
			GameBoard[shapeArr[i].getY()][shapeArr[i].getX()] = true;

	}

	void move(char keyPressed,bool GameBoard[][12]) {

		for (int i = 0; i < 4; i++) 
			{
			if (keyPressed == 'a' && shapeArr[i].getType() != ' ')  //Left button
				if (isShapeCanMove(LEFT, GameBoard))
					shapeArr[i].move(LEFT, GameBoard);

			if (keyPressed == 'd' && shapeArr[3 - i].getType() != ' ')  //Right button
				if (isShapeCanMove(RIGHT, GameBoard))
					shapeArr[i].move(RIGHT, GameBoard);

				 if (keyPressed == 's' && shapeArr[i].getType() != ' ')  //down to bottom fast
					 gravitySpeed = 30;
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
			if (shapeArr[i].canMove(dir, gameBaord) == false)
				res=false;

		return res;
	}
};

#endif // !__Shape
