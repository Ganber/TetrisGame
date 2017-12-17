#include <iostream>
using namespace std;

#include "GotoXY.h"
#include"Point.h"
#include "Shape.h"
#include "Board.h"


void main() {

	Shape s1(Shape::line);
	Shape s2(Shape::cube);
	Shape s3(Shape::joker);
	Shape s4(Shape::bomb);
	initBoard();

	s1.draw();
	s1.gravity();

		s2.draw();
		s2.gravity();


		s3.draw();
		s3.gravity();

		s4.draw();
		s4.gravity();
}