#ifndef __Shape
#define __Shape
#include "Point.h"

class Shape {
private:
	bool isRotated;
	int type;
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
