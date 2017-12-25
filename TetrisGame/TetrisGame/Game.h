#ifndef __Game
#define __Game
using namespace std;
#include <iostream>
#include "Shape.h"
#include <ctime>
#include <cstdlib>
#include <conio.h>

class Game {
public:
	enum border { WIDTH = 10, HEIGHT = 15 };
	enum asciiShapes {LongCube=219,TopCube=223};
	char mapArr[HEIGHT][WIDTH + 1] = { false }; // + 1 becuase of the boards.

private:
    int gameSpeed;
	int gameScore;
	int shapeCount;
public:
	Game()
	{ 
	gameSpeed = 400;
	gameScore = 0;
	shapeCount = 0;
	}

	void runGame() {
		initBoard();
		initMenu();
		char keyPressed = 0;

		while (1)
		{
			keyPressed = 0;
	    	if (_kbhit())
				keyPressed = _getch();
				if (keyPressed == '1') 
				{ //user want to start new game.

					startNewGame();
				}
		}
	}


	void initBoard() {
		gotoxy(0, 0);
		for (int i = 0; i < HEIGHT; i++) {
			cout << (char)LongCube <<"          "<<(char)LongCube<< endl;
		}
		for (int i = 0; i < WIDTH+2; i++) {
			cout <<(char)TopCube;
		}

		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH + 1; j++) {
				mapArr[i][j] = ' ';
			}
		}


	}
	void initMenu() {
		gotoxy(20, 1);
		cout << "Game Score:      ";
		gotoxy(20, 2);
		cout << "Shapes dropped:      ";
		gotoxy(20, 3);
		cout << "--------------------";
		gotoxy(20, 4);
		cout << "| (1) New Game     |";
		gotoxy(20, 5);
		cout << "| (2) Pause/Resume |";
		gotoxy(20, 6);
		cout << "| (3) Speed down   |";
		gotoxy(20, 7);
		cout << "| (4) Speed up     |";
		gotoxy(20, 8);
		cout << "| (9) Exit Game    |";
		gotoxy(20, 9);
		cout << "--------------------";
	}
	Shape dropNewShape() {
		
	    Shape s1(rand()%4); //create a random shape.
		s1.draw();
		clock_t startTime = clock(); //Start timer for speed.
		double msPassed;


		while (s1.getShapeArr()[0].getY() < Game::HEIGHT + 1 && s1.isShapeCanMove(Point::DOWN, mapArr)) {
			msPassed = ((clock() - startTime)); //miliSecond passed..

			if (_kbhit()) {
				keyPressed(_getch(),s1);
			}

			if (msPassed > gameSpeed) { // every 'gameSpeed' ms move down shape.
				for (int i = 0; i < 4; i++) {
					if (s1.getShapeArr()[i].getType() != ' ')
						s1.getShapeArr()[i].move(Point::DOWN);
				}
				msPassed = 0; //starting the timer again.
				startTime = clock();
			}

		}
		gameSpeed = 500; //TODO: need fix this. game shdln't be reset to 500 every shape.
		return s1;

	}
	void updateCompltedLine(int line) {
		for (int y = line; y > 0; y--)
			for (int x = 1; x < WIDTH + 1; x++)
			{
				gotoxy(x,y);
				cout << mapArr[y-1][x];
				mapArr[y][x] = mapArr[y - 1][x];
			}


	}
	void updateScoreAndCount() {
		gotoxy(32, 1);
		cout << gameScore;
		gotoxy(35, 2);
		cout << shapeCount;
	}
	bool gameOver(){
		for (int i = 0; i < WIDTH + 1; i++)
			if (mapArr[0][i] != ' ') {
				gotoxy(2, HEIGHT + 1);
				cout << "Game Over" << endl << endl;
				return true;
			}
			
				return false;
	}

	void startNewGame() {
		bool completedLine;
		int numOfLinesComplted = 0;
		//init the game settings.
		gameScore = 0;
		shapeCount = 0;
		initBoard();
		initMenu();
		updateScoreAndCount();


		while (!gameOver()) {
			Shape s1 = dropNewShape(); //s1 is the shape after she fell down
			shapeCount++;

			for (int i = 0; i < 4; i++) //put the shape in the map array of the game 
				mapArr[s1.getShapeArr()[i].getY()][s1.getShapeArr()[i].getX()] = s1.getShapeArr()[i].getType();


			//for each point in the shape, check if she complted a line :
			for (int i = 3; i >= 0; i--) { // need to start from the top to bottom.
				completedLine = true; //we assume that the line is complted.
				for (int j = 1; j < WIDTH + 1; j++) {
					if (mapArr[s1.getShapeArr()[i].getY()][j] == ' ') //that's mean that the line isn't complted.
						completedLine = false;
				}
				if (completedLine) {
					numOfLinesComplted++;
					updateCompltedLine(s1.getShapeArr()[i].getY()); //this update the board and move above shapes down.
				}
			
			}

			switch (numOfLinesComplted)
			{
			case 1: {
				gameScore += 40;
				break;
			}
			case 2: {
				gameScore += 100;
				break;
			}
			case 3: {
				gameScore += 300;
				break;
			}
			case 4: {
				gameScore += 1200;
				break;
			}
			default:
				break;
			}
			updateScoreAndCount();
		}
	}

	void keyPressed(int keyCode, Shape &s1) {

		switch (keyCode)
		{
		case 75:
		{ // left Arrow
			if (s1.isShapeCanMove(Point::LEFT, mapArr))
				for (int i = 0; i < 4; i++)
					s1.getShapeArr()[i].move(Point::LEFT);
			break;
		}
		case 77:
		{ // right arrow
			if (s1.isShapeCanMove(Point::RIGHT,mapArr))
				for (int i = 0; i < 4; i++)
					s1.getShapeArr()[3 - i].move(Point::RIGHT);
			break;
		}

		case 80:
		{ // down arrow
			gameSpeed = gameSpeed / 10; //TODO: this need to happen just for 1 falling piece.
			break;
		}

		case 57:
		{ // '9' -> exit game
			exit(0);
			break;
		}

		case 50:
		{ // '2' -> pause Game
			gotoxy(2, HEIGHT + 3);
			cout << "Game Paused" << endl;
			keyCode = 0;
			while (keyCode != '2') {
				keyCode = _getch();
			}
			gotoxy(2, HEIGHT + 3);
			cout << "              " << endl;
			break;
		}
		case 52:
		{ // '4' -> slow down game
			gameSpeed += 100;
			break;
		}
		case 51:
		{ // '3' -> speed up game
			gameSpeed -= 100;
			break;
		}
		case 32: { // Space key
			if (s1.getType() == Shape::line)
				s1.rotate();
		}

		}
	}
};

#endif // !__Game

