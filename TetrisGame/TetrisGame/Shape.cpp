#include "Shape.h"
#include "Game.h"

enum ArrowsKeys {
	leftArrow = 75, rightArrow = 77, Down = 80, space = 32
};

Shape::Shape(int _type) {
	type = _type;

	if (type == line) {
		shapeArr[0] = Point(5, 0, Point::RegularShape);
		shapeArr[1] = Point(6, 0, Point::RegularShape);
		shapeArr[2] = Point(7, 0, Point::RegularShape);
		shapeArr[3] = Point(8, 0, Point::RegularShape);
	}
	if (type == cube) {
		shapeArr[0] = Point(5, 1, Point::RegularShape);
		shapeArr[1] = Point(6, 1, Point::RegularShape);
		shapeArr[2] = Point(5, 0, Point::RegularShape);
		shapeArr[3] = Point(6, 0, Point::RegularShape);
	}

	 if (type == bomb) 
		shapeArr[0] = Point(6, 0, Point::Bomb);
	
	 if (type == joker) 
		shapeArr[0] = Point(6, 0, Point::Joker);
	
	 if (type == PlusShape) {
		shapeArr[0] = Point(5, 0, Point::RegularShape);
		shapeArr[1] = Point(6, 0, Point::RegularShape);
		shapeArr[2] = Point(7, 0, Point::RegularShape);
		shapeArr[3] = Point(6, 1, Point::RegularShape);
	 }

	 if (type == Lshape) {
		 shapeArr[1] = Point(5, 0, Point::RegularShape);
		 shapeArr[0] = Point(5, 1, Point::RegularShape);
		 shapeArr[2] = Point(6, 0, Point::RegularShape);
		 shapeArr[3] = Point(7, 0, Point::RegularShape);
	 }
	 if (type == ZShape) {
		 shapeArr[0] = Point(5, 0, Point::RegularShape);
		 shapeArr[1] = Point(6, 0, Point::RegularShape);
		 shapeArr[2] = Point(6, 1, Point::RegularShape);
		 shapeArr[3] = Point(7, 1, Point::RegularShape);
	 }
}

void Shape::draw() {
	for (int i = 0; i < 4; i++) {
		if (shapeArr[i].getType() != ' ')
			this->getShapeArr()[i].draw();
	}
}
void Shape::rotate(Point rotPoint, char gameBaord[][Game::WIDTH +1]) {
	//Generic rotate with linear transformation.

	if (type == cube)
		return;
		Point vr; //this is the vector that we use as the axis of rotation.
		Point vt; //this is the vector that will be the result after we use the transformation

		//check that we can rotate the shape..
		for (int i = 0; i < 4; i++) {
			vr.setXY(shapeArr[i].getX() - rotPoint.getX(), shapeArr[i].getY() - rotPoint.getY()); // we substruct the rotPoint from the original vector.
			vt.setXY((-1 * vr.getY()), vr.getX()); //here we multiply the rotate matric with the vector.
			vt.setXY(vt.getX() + rotPoint.getX(), vt.getY() + rotPoint.getY()); //we add the rotPoint values.
			if (gameBaord[vt.getY()][vt.getX()] != ' ')
				return;
			if (vt.getX() > Game::WIDTH || vt.getX() <= 0)
				return;
			
		}

		if (type != cube)
			deleteShapeFromBoard();

		for (int i = 0; i < 4; i++) {
			vr.setXY(shapeArr[i].getX() - rotPoint.getX(), shapeArr[i].getY() - rotPoint.getY()); // we substruct the rotPoint from the original vector.
			vt.setXY((-1 * vr.getY()), vr.getX()); //here we multiply the rotate matric with the vector.
			vt.setXY(vt.getX() + rotPoint.getX(), vt.getY() + rotPoint.getY()); //we add the rotPoint values.
			shapeArr[i].setXY(vt.getX(), vt.getY()); //copy the new values the the original matrix.
		}

		for (int i = 0; i < 4; i++)
			shapeArr[i].draw();

	}

bool Shape::isShapeCanMove(int dir, char gameBaord[][Game::WIDTH +1]) {
	bool res = true;

	for (int i = 0; i < 4; i++)
		if (shapeArr[i].canMove(dir, gameBaord) == false && shapeArr[i].getType() != ' ')
			res = false;

	return res;
}

int Shape::moveShape(int DIR, char mapArr[][Game::WIDTH +1])
{
	int shapeSize = 0;

	for (int i = 0; i < 4; i++)
		if (shapeArr[i].getType() != ' ')
			shapeSize++;


	switch (DIR)
	{
	case Down: {
		if (isShapeCanMove(Down, mapArr)) {
			deleteShapeFromBoard();
			for (int i = 0; i < shapeSize; i++) {
				shapeArr[i].setY(shapeArr[i].getY() + 1);
				shapeArr[i].draw();
			}
			
		}
		break;
	}
	case leftArrow: {
		if (isShapeCanMove(leftArrow, mapArr)) {
			deleteShapeFromBoard();
			for (int i = 0; i < shapeSize; i++) {
				shapeArr[i].setX(shapeArr[i].getX() - 1);
				shapeArr[i].draw();
			}
		}
		break;
	}
	case rightArrow: {
		if (isShapeCanMove(rightArrow, mapArr)) {
			deleteShapeFromBoard();
			for (int i = 0; i < shapeSize; i++) {
				shapeArr[i].setX(shapeArr[i].getX() + 1);
				shapeArr[i].draw();
			}
		}
		break;
	}
	case space: {

		rotate(shapeArr[1], mapArr);
		break;
	}
	default:
		break;
	}


	return 0;
}

void Shape::deleteShapeFromBoard() {
	int shapeSize = 0;

	for (int i = 0; i < 4; i++)
		if (shapeArr[i].getType() != ' ')
			shapeSize++;

	for (int i = 0; i < shapeSize; i++)
		shapeArr[i].draw(' ');
}