#ifndef __Shape
#define __Shape
#include "Point.h"
#include <conio.h>

#define SPC (char) 32

class Shape {
private:
	enum colors
	{
		Black, Blue, Green, Cyan, Red, Magenta, Brown,
		Light_Gray, Dark_Gray, Light_Blue, Light_Green,
		Light_Cyan, Light_Red, LightMagenta, Yellow, White
	};
	int shapeSpeed;
	bool isRotated;
	int type;
	int color;
	Point shapeArr[4]; //For all kind of shapes
	

public:
	enum border { WIDTH = 10, HEIGHT = 15 };
	enum Shapes { line, cube, bomb, joker };
	Shape(int _Type,int gameSpeed);
	Shape(const Shape& s1);
	void draw();
	void rotate();
	bool isShapeCanMove(int dir, char gameBaord[][12]);
	void keyPressed(int keyCode, char GameBoard[][12],int& gameSpeed);
	Point* getShapeArr();
	void setShapeSpeed(int newSpeed);
	int getShapeSpeed()const;
};

#endif // !__Shape
