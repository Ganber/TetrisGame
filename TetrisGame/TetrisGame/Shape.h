#ifndef __Shape
#define __Shape
#include "Point.h"

class Shape {
private:
	int type;

	Point shapeArr[4]; //For all kind of shapes

public:
	enum border { WIDTH = 10, HEIGHT = 15 };
	enum Shapes { line, cube, bomb, joker ,Lshape, PlusShape,ZShape};
	Shape(int _Type);
	Shape() {}
	int getType() { return type; }
	virtual void draw();
	void rotate(Point rotPoint, char gameBaord[][WIDTH +1]);
	bool isShapeCanMove(int dir, char gameBaord[][WIDTH +1]);
	virtual int moveShape(int DIR, char mapArr[][WIDTH +1]);
	virtual char getOverridedPiece() { return ' '; }
	void deleteShapeFromBoard();
	virtual int createExplotion(char mapArr[][WIDTH +1]) { return 0; }
	Point* getShapeArr() { return shapeArr; }
};

#endif // !__Shape
