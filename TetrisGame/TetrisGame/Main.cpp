#include <iostream>
using namespace std;

#include "GotoXY.h"
#include"Point.h"
#include "Shape.h"


void main() {

	Shape s1(Shape::line);
	Shape s2(Shape::square);
	Shape s3(Shape::joker);
	Shape s4(Shape::bomb);
	

		s1.draw();
		s1.gravity();


}