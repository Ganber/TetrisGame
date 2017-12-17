#ifndef __Shape
#define __Shape
#include "Point.h"
#include <conio.h>

class Shape {
	enum colors 
	{Black,Blue,Green,Cyan,Red,Magenta,Brown,
	 Light_Gray,Dark_Gray,Light_Blue,Light_Green,
	 Light_Cyan,Light_Red,LightMagenta,Yellow,White};
	
	int type;
	int color;
	Point shapeArr[4][4];

public:
	enum Shapes { line, cube, bomb, joker };

	Shape(int _type) {
		type = _type;

		if (type == line) {
			color = Yellow;
			shapeArr[3][0] = Point(5, 1, 'o');
			shapeArr[3][1] = Point(6, 1, 'o');
			shapeArr[3][2] = Point(7, 1, 'o');
			shapeArr[3][3] = Point(8, 1, 'o');
		}
		else if (type == cube) {
			color = Green;
			shapeArr[2][0] = Point(5, 0, 'o');
			shapeArr[2][1] = Point(6, 0, 'o');
			shapeArr[3][0] = Point(5, 1, 'o');
			shapeArr[3][1] = Point(6, 1, 'o');
		}
		else if (type == bomb) {
			color = Light_Red;
			shapeArr[3][0] = Point(6, 1, '@');
		}
		else if (type == joker) {
			color = White;
			shapeArr[3][0] = Point(6, 1, 'A');
		}
	}

	void draw() {
		SetColor(color);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				if (shapeArr[i][j].getType() != ' ')
					shapeArr[i][j].draw();
		}
	}

	void gravity() {
		for (int k = 0; k <Point::HEIGHT; k++) {

			for (int i = 3; i >= 0; i--) {
				for (int j = 0; j < 4; j++)
					if (shapeArr[i][j].getType() != ' ')
					shapeArr[i][j].moveDown();

				if (_kbhit()) {
					char keyPressed = _getch();
					move(keyPressed);
				}
			}
			Sleep(200);


		}
	}

	void move(char keyPressed) {

		for (int i = 0; i < 4; i++) 
			for (int j = 0; j < 4; j++) 
			{
				if (keyPressed == 'a' && shapeArr[i][j].getType() != ' ')  //Left button
					if (shapeArr[i][j].moveLeft() == false)
						return;

				 if (keyPressed == 'd' && shapeArr[3-i][3-j].getType() != ' ')  //Right button
					if (shapeArr[3-i][3-j].moveRight() == false)
						return;
			}
		
	}
};

#endif // !__Shape
