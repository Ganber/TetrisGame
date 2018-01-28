#include "Bomb.h"

int Bomb::createExplotion(char mapArr[][Game::WIDTH+1]) {

 int hitShapeCounter = 0;

 for (int i = -1; i < 2; i++) {
	 for (int j = -1; j < 2; j++) {
		 int y = this->getShapeArr()[0].getY() + i; //the y value of the bomb +i
		 int x = this->getShapeArr()[0].getX() + j; //the x value of the bomb +j
		 if (y < Game::HEIGHT && x > 0 && x <= Game::WIDTH)
			 if (mapArr[y][x] != ' ') {
				 mapArr[y][x] = ' ';
				 hitShapeCounter++;
			 }
	 }
 }
 return hitShapeCounter;

	}

int Bomb::moveShape(int DIR, char mapArr[][Game::WIDTH + 1]) {
	switch (DIR)
	{
	case leftArrow: {
		if (this->getShapeArr()[0].getX() > 0)
			if (mapArr[this->getShapeArr()[0].getY()][this->getShapeArr()[0].getX() - 1] != ' ')
				return createExplotion(mapArr);

		if (this->isShapeCanMove(leftArrow, mapArr)) {
			this->getShapeArr()[0].draw(' ');
			this->getShapeArr()[0].setX(this->getShapeArr()[0].getX() - 1);
			this->getShapeArr()[0].draw();
		}

		break;
	}
	case rightArrow: {
		if (this->getShapeArr()[0].getX() <= Game::WIDTH)
			if (mapArr[this->getShapeArr()[0].getY()][this->getShapeArr()[0].getX() + 1] != ' ')
				return createExplotion(mapArr);

		if (this->isShapeCanMove(rightArrow, mapArr)) {
			this->getShapeArr()[0].draw(' ');
			this->getShapeArr()[0].setX(this->getShapeArr()[0].getX() + 1);
			this->getShapeArr()[0].draw();
		}
		break;
	}

	case Down: {
		if (mapArr[this->getShapeArr()[0].getY() + 1][this->getShapeArr()[0].getX()] != ' ')
			return createExplotion(mapArr);

		if (this->isShapeCanMove(Down, mapArr)) {
			this->getShapeArr()[0].draw(' ');
			this->getShapeArr()[0].setY(this->getShapeArr()[0].getY() + 1);
			this->getShapeArr()[0].draw();
		}
		break;
	}
	default:
		break;
	}

	return 0;
}