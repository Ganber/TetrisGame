#ifndef __Shape
#define __Shape
#include "Point.h"

class Shape {
private:
	enum class RotationState {zeroRotation,oneRotation,twoRotation,threeRotation};
	int RotState;
	int type;

	Point shapeArr[4]; //For all kind of shapes

public:
	enum border { WIDTH = 10, HEIGHT = 15 };
	enum Shapes { line, cube, bomb, joker ,Lshape, PlusShape,ZShape};
	Shape(int _Type);
	Shape() {}
	int getType() { return type; }
	void draw();
	void rotate(Point rotPoint, char gameBaord[][11]);
	bool isShapeCanMove(int dir, char gameBaord[][11]);
	virtual int moveShape(int DIR, char mapArr[][11]);
	void deleteShapeFromBoard();
	virtual int createExplotion(char mapArr[][11]) { return 0; }
	Point* getShapeArr() { return shapeArr; }
};

#endif // !__Shape
