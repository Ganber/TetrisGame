#ifndef __Shape
#define __Shape
#include "Point.h"



class Shape {
private:
	enum colors
	{
		Black, Blue, Green, Cyan, Red, Magenta, Brown,
		Light_Gray, Dark_Gray, Light_Blue, Light_Green,
		Light_Cyan, Light_Red, LightMagenta, Yellow, White
	};
	bool isRotated;
	int type;
	int color;
	Point shapeArr[4]; //For all kind of shapes
	

public:
	enum border { WIDTH = 10, HEIGHT = 15 };
	enum Shapes { line, cube, bomb, joker };
	Shape(int _Type);
	int getType() { return type; }
	void draw();
	void rotate();
	bool isShapeCanMove(int dir, char gameBaord[][11]);
	bool isShapeCanRotate();
	Point* getShapeArr();

};

#endif // !__Shape
