#include <iostream>
using namespace std;

#include "GotoXY.h"
#include"Point.h"
#include "Shape.h"

void main() {

	Shape s1(1);
	Shape s2(1);
	s1.draw();
	s1.move();

	s2.draw();
	s2.move();
}