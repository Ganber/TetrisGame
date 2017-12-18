#include "Game.h"
#include <iostream>
#include "Point.h"
#include "Shape.h"

#define _TOP_CUBE (char)223
#define _BOT_CUBE (char)220
#define _Long_CUBE (char)219
#define ESC (char) 27

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

void gameRun() {

	initBoard();

	char keyPressed = 0;

	while (!_kbhit() && keyPressed != ESC) //TODO: fix the ESC to exit
	{
		if (_kbhit()) {
			keyPressed = _getch();
		}

		Shape s1(Shape::line);
		Shape s2(Shape::cube);
		Shape s3(Shape::joker);
		Shape s4(Shape::bomb);


		s2.draw();
		s2.gravity();

		s1.draw();
		s1.gravity();


		s3.draw();
		s3.gravity();

		s4.draw();
		s4.gravity();
	}
}
