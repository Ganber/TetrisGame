#include "Joker.h"


int Joker::moveShape(int DIR, char mapArr[][Game::WIDTH + 1]) {

	switch (DIR) {
	case Down: {
		if (isShapeCanMove(Down, mapArr)) {
			char cSave = mapArr[getShapeArr()[0].getY() + 1][getShapeArr()[0].getX()];
			deleteShapeFromBoard();
			this->getShapeArr()[0].setY(this->getShapeArr()[0].getY() + 1);
			this->getShapeArr()[0].draw();
			gotoxy(this->getShapeArr()[0].getX(), this->getShapeArr()[0].getY() - 1);
			cout << overridedPiece;
			overridedPiece = cSave;
		}


		break;
	}
	case leftArrow: {
		if (isShapeCanMove(leftArrow, mapArr)) {
			char cSave = mapArr[getShapeArr()[0].getY()][getShapeArr()[0].getX() - 1];
			deleteShapeFromBoard();
			this->getShapeArr()[0].setX(this->getShapeArr()[0].getX() - 1);
			this->getShapeArr()[0].draw();
			gotoxy(this->getShapeArr()[0].getX() + 1, this->getShapeArr()[0].getY());
			cout << overridedPiece;
			overridedPiece = cSave;
		}
		break;
	}
	case rightArrow: {
		if (isShapeCanMove(rightArrow, mapArr)) {
			char cSave = mapArr[getShapeArr()[0].getY()][getShapeArr()[0].getX() + 1];
			deleteShapeFromBoard();
			this->getShapeArr()[0].setX(this->getShapeArr()[0].getX() + 1);
			this->getShapeArr()[0].draw();
			gotoxy(this->getShapeArr()[0].getX() - 1, this->getShapeArr()[0].getY());
			cout << overridedPiece;
			overridedPiece = cSave;
		}
		break;
	}
	}
	return 0;
}