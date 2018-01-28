#ifndef __Joker
#define __Joker
#include "Shape.h"
#include "Game.h"

class Joker : public Shape {
private:


public:
	Joker():Shape(joker){}

	int moveShape(int DIR, char mapArr[][11]) {
		//TODO: moveShape as a Joker..
		return 1;
	}
};

#endif // !__Shape
