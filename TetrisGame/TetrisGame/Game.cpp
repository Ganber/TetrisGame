#include "Game.h"
#include <iostream>
#include "Point.h"

#define _TOP_CUBE (char)223
#define _BOT_CUBE (char)220
#define _Long_CUBE (char)219

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

	char arr[Point::HEIGHT + 3][Point::WIDTH + 3];

	for (int i = 0; i < Point::HEIGHT + 3; i++)
		for (int j = 0; j < Point::WIDTH + 3; j++) {

			if (i == Point::HEIGHT + 2)
				arr[i][j] = _TOP_CUBE;
			else if (j == 0 || j == Point::WIDTH + 2)
				arr[i][j] = _Long_CUBE;
			else
				arr[i][j] = ' ';
		}

	for (int i = 0; i < Point::HEIGHT + 3; i++) {
		for (int j = 0; j < Point::WIDTH + 3; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}

