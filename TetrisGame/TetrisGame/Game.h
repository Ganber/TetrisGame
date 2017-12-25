#ifndef __Game
#define __Game

using namespace std;
#include <iostream>
#include "Shape.h"
#include <ctime>
#include <cstdlib>


#define ESC (char) 27

class Game {
public:
	enum border { WIDTH = 10, HEIGHT = 15 };


private:
	char boardArr[HEIGHT + 3][WIDTH + 3];
	char mapArr[HEIGHT + 2][WIDTH + 2] = { false };
    int gameSpeed;
public:
	Game() { gameSpeed = 500; }

	void runGame() {

		initBoard();
		initMenu();
		char keyPressed = 0;

		while (1)
		{
			if (_kbhit())
				keyPressed = _getch();

			if (keyPressed == '1')
				createShape();

			for (int i = 0; i < WIDTH + 2; i++)
				if (mapArr[0][i] != ' ') {
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


		for (int i = 0; i < HEIGHT + 2; i++) {
			for (int j = 0; j < WIDTH + 2; j++) {
				mapArr[i][j] = ' ';
			}
		}


	}

	void initMenu() {
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

	void createShape() {
		Shape s1(rand()%4, gameSpeed); //create a random shape.

		s1.draw();
		clock_t startTime;
		double msPassed;
		startTime = clock(); //Start timer for speed.


		while (s1.getShapeArr()[0].getY() < Shape::HEIGHT + 1 && s1.isShapeCanMove(Point::DOWN, mapArr)) {
			msPassed = ((clock() - startTime)); //miliSecond passed..
			if (_kbhit()) {
				s1.keyPressed(_getch(), mapArr, gameSpeed);
			}

			if (msPassed > s1.getShapeSpeed()) { //if more than 0.4 sec passed than move down
				for (int i = 0; i < 4; i++) {
					if (s1.getShapeArr()[i].getType() != ' ')
						s1.getShapeArr()[i].move(Point::DOWN);
				}
				msPassed = 0;
				startTime = clock();
			}

		}

		for (int i = 0; i < 4; i++) //set the map array of the game 
			mapArr[s1.getShapeArr()[i].getY()][s1.getShapeArr()[i].getX()] = s1.getShapeArr()[i].getType();

	}


};

#endif // !__Game
