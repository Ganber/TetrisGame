#ifndef __Joker
#define __Joker
#include "Shape.h"
#include "Game.h"

class Joker : public Shape {
	enum keys {
		leftArrow = 75, rightArrow = 77, Down = 80
	};
private:
	char overridedPiece=' ';

public:
	Joker():Shape(joker){}

	char getOverridedPiece() { return overridedPiece; }
	int moveShape(int DIR, char mapArr[][Game::WIDTH + 1]);
};

#endif // !__Shape
