#include "Game.h"
#include <iostream>
#include "Point.h"
#include "Shape.h"

#define _TOP_CUBE (char)223
#define _BOT_CUBE (char)220
#define _Long_CUBE (char)219
#define ESC (char) 27



void gameRun() {
	bool mapArr[17][12] = { false }; //TODO: move it from here and use height and width (+2). (to Game CLASS)
	initBoard();

	char keyPressed = 0;

	while (!_kbhit() && keyPressed != 'k') //TODO: fix the ESC to exit and change 'k' to ECS
	{
		if (_kbhit()) {
			keyPressed = _getch();
		}

		Shape s1(Shape::line);
		Shape s2(Shape::cube);
		Shape s3(Shape::joker);
		Shape s4(Shape::bomb);



		s2.draw();
		s2.gravity(mapArr);


		s1.draw();
		s1.gravity(mapArr);


		s3.draw();
		s3.gravity(mapArr);

		s4.draw();
		s4.gravity(mapArr);

		s2.draw();
		s2.gravity(mapArr);
	}
}

void initBoard() {
	/*
	▄▄▄▄▄▄▄▄▄▄▄▄▄
	█           █
	█           █
	█           █
	█           █
	█           █
	█           █
	█           █
	█           █
	█           █
	█           █
	█           █
	█           █
	█           █
	█           █
	█           █
	█           █
	▀▀▀▀▀▀▀▀▀▀▀▀▀
	*/

	char arr[HEIGHT + 3][WIDTH + 3];

	for (int i = 0; i < HEIGHT + 3; i++)
		for (int j = 0; j < WIDTH + 3; j++) {

			if (i == HEIGHT + 2)
				arr[i][j] = _TOP_CUBE;
			else if (j == 0 || j == WIDTH + 2)
				arr[i][j] = _Long_CUBE;
			else
				arr[i][j] = ' ';
		}

	for (int i = 0; i < HEIGHT + 3; i++) {
		for (int j = 0; j < WIDTH + 3; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}