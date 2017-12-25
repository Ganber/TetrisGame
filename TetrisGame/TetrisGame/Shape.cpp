#include "Shape.h"
#include "Game.h"


Shape::Shape(int _type) {
	type = _type;
	isRotated = false;

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
Point* Shape::getShapeArr() {
	return shapeArr;
}
void Shape::draw() {
	SetColor(color);
	for (int i = 0; i < 4; i++) {
		if (shapeArr[i].getType() != ' ')
			shapeArr[i].draw();
	}
}
void Shape::rotate() {

	if (shapeArr[0].getY() > 1) {
		if (shapeArr[0].getX() > Game::WIDTH - 2 && isRotated) {
			//this is in case that the shape is too close to the right WALL.
			for (int i = 0; i < 4; i++)
				shapeArr[i].movePoint(shapeArr[i].getX() - (4 - ((Game::WIDTH + 1) - shapeArr[i].getX())), shapeArr[i].getY());
		}

		for (int i = 0; i < 4; i++)

			if (!isRotated) {
				int newX = shapeArr[i].getX() - i;
				int newY = shapeArr[i].getY() - i;
				shapeArr[i].movePoint(newX, newY);
			}
			else {
				int newX = shapeArr[i].getX() + i;
				int newY = shapeArr[i].getY() + i;
				shapeArr[i].movePoint(newX, newY);
			}

			isRotated = !isRotated;
	}
}
bool Shape::isShapeCanMove(int dir, char gameBaord[][11]) {
	bool res = true;

	for (int i = 0; i < 4; i++)
		if (shapeArr[i].canMove(dir, gameBaord) == false && shapeArr[i].getType() != ' ')
			res = false;

	return res;
}

bool Shape::isShapeCanRotate() { //TODO:need to check this.
	if (shapeArr[0].getY() > 2) {
		return true;


	}

	return true;
}