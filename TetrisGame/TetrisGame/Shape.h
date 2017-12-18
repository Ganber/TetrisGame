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

	Shape(int _type) {

		type = _type;
		gravitySpeed = 200;
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

	void gravity() {

		while (shapeArr[0].getY() < HEIGHT + 1) {	//TODO: hit other shape

			for (int i = 0; i < 4; i++) {
				if (shapeArr[i].getType() != ' ')
					shapeArr[i].moveDown();
			}

			if (_kbhit()) {
				char keyPressed = _getch();
				if (keyPressed == SPC && type == line)
					rotate();
				else
					move(keyPressed);
			}

			Sleep(gravitySpeed);
		}
	}

	void move(char keyPressed) {

		for (int i = 0; i < 4; i++) 
			{
				if (keyPressed == 'a' && shapeArr[i].getType() != ' ')  //Left button
					if (shapeArr[i].moveLeft() == false)
						return;

				 if (keyPressed == 'd' && shapeArr[3-i].getType() != ' ')  //Right button
					if (shapeArr[3-i].moveRight() == false)
						return;

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

};

#endif // !__Shape
