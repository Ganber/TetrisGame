#ifndef __Bomb
#define __Bomb
#include "Shape.h"
#include "Game.h"

class Bomb : public Shape {
	enum keys {
		leftArrow = 75, rightArrow = 77, Down = 80
	};

private:


public:
	Bomb() : Shape(bomb) {}

	int createExplotion(char mapArr[][Game::WIDTH +1]);
	int moveShape(int DIR, char mapArr[][Game::WIDTH + 1]) override;


};

#endif // !__Shape
