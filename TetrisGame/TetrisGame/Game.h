#ifndef __Game
#define __Game

using namespace std;
#include <iostream>
#include "Shape.h"

#define _TOP_CUBE (char)223
#define _BOT_CUBE (char)220
#define _Long_CUBE (char)219
#define ESC (char) 27

class Game {
public:
	enum border { WIDTH = 10, HEIGHT = 15 };
    int gameGravity = 500;

private:
	char boardArr[HEIGHT + 3][WIDTH + 3];
	bool mapArr[HEIGHT + 2][WIDTH + 2] = { false };

public:
	Game(){
		gameGravity = 500;
	}

	void gameRun() {

		initBoard();
		menu();

		char keyPressed = 0;

		while (keyPressed != '9')
		{
			if (_kbhit())
				keyPressed = _getch();

			int check = 0;

			if (keyPressed == '1')
				check = newGame();
				if (check == 9) {
					gotoxy(2, HEIGHT + 3);
					cout << "Game Over" << endl << endl;
					return;
				}
		}
	}

	void initBoard() {
		for (int i = 0; i < HEIGHT + 3; i++)
			for (int j = 0; j < WIDTH + 3; j++) {

				if (i == HEIGHT + 2)
					boardArr[i][j] = _TOP_CUBE;
				else if (j == 0 || j == WIDTH + 2)
					boardArr[i][j] = _Long_CUBE;
				else
					boardArr[i][j] = ' ';
			}

		for (int i = 0; i < HEIGHT + 3; i++) {
			for (int j = 0; j < WIDTH + 3; j++) {
				cout << boardArr[i][j];
			}
			cout << endl;
		}
	}

	void menu() {
		gotoxy(20, 1);
		cout << "--------------------";
		gotoxy(20, 2);
		cout << "| (1) New Game     |";
		gotoxy(20, 3);
		cout << "| (2) Pause/Resume |";
		gotoxy(20, 4);
		cout << "| (3) Speed down   |";
		gotoxy(20, 5);
		cout << "| (4) Speed up     |";
		gotoxy(20, 6);
		cout << "| (9) Exit Game    |";
		gotoxy(20, 7);
		cout << "--------------------";
	}

	int newGame() {
		Shape s1(rand()%4,&gameGravity);

		s1.draw();
		return s1.gravity(mapArr);
	}
};

#endif // !__Game
