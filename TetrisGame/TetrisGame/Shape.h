#ifndef __Shape
#define __Shape
#include "Point.h"

class Shape {

	int type;
	Point shapeArr[4][4];

public:
	Shape(int _type) {
		type = _type;
		
		if (type == 1) {
			shapeArr[0][0] = Point(5, 0);
			shapeArr[0][1] = Point(6, 0);
			shapeArr[0][2] = Point(7, 0);
			shapeArr[0][3] = Point(8, 0);
		}
	}

	void draw() {
		for (int i = 0; i < 4; i++) {
			shapeArr[0][i].draw();
		}
	}

	void move() {
		while (shapeArr[0][0].getY() < 14) {
			for (int i = 0; i < 4; i++) 
				shapeArr[0][i].move();
			Sleep(100);
		}
	}

};

#endif // !__Shape
