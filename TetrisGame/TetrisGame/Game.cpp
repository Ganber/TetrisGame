#include <ctime>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include "Game.h"
#include "Shape.h"
#include "Bomb.h"
#include "Joker.h"

enum keys {
	leftArrow = 75, rightArrow = 77, downArrow = 80, space = 32, NewGame = 49,
	pauseGame = 50, slowDown = 51, speedUp = 52, exitGame = 57
};

Game::Game() {
	gameSpeed = 300;
	speedSaver = 300;
	gameScore = 0;
	shapeCount = 0;
}

void Game::runGame() {
	initBoard();
	initMenu();
	char keyPressed = 0;

	while (true)
	{
		keyPressed = 0;
		if (_kbhit())
			keyPressed = _getch();
		if (keyPressed == '1') { //user want to start new game.
			startNewGame();
		}
	}
}

void Game::initBoard() {

	system("CLS");
	gotoxy(0, 0);
	for (int i = 0; i < HEIGHT; i++) {
		cout << (char)LongCube << "          " << (char)LongCube << endl;
	}
	for (int i = 0; i < WIDTH + 2; i++) {
		cout << (char)TopCube;
	}

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH + 1; j++) {
			mapArr[i][j] = ' ';
		}
	}
}

void Game::initMenu() {
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

Shape* Game::dropNewShape() {
	char keyprees;
	int explodedPieces = 0;
	char OP = ' ';
	Shape* s1 = createRandomShape(); //create a random shape.
	s1->draw();

	clock_t startTime = clock(); //Start timer for speed.
	double msPassed;

	while (s1->isShapeCanMove(Point::Down, mapArr)) {
		msPassed = ((clock() - startTime)); //miliSecond passed..

		if (_kbhit()) {
			keyprees = _getch();
			if (s1->getType() == Shape::joker && keyprees == 's')
				break;
			else
				explodedPieces=keyPressed(keyprees,s1);
				
		}
		if (explodedPieces > 0)
			break;

		if (msPassed > gameSpeed) { // every 'gameSpeed' ms move down shape.

			s1->moveShape(downArrow, mapArr);

			gameScore += int(80 / gameSpeed);

			msPassed = 0; //starting the timer again.
			startTime = clock();
			Sleep(1);
		}

	}


	gameScore = gameScore - (50 * explodedPieces);
	gameSpeed = speedSaver;
	return s1;

}

void Game::updateCompltedLine(int line) {
	//when a complte line event happend, all the shapes above it need to drop down.
	for (int y = line; y > 0; y--)
		for (int x = 1; x < WIDTH + 1; x++)
		{
			gotoxy(x, y);
			cout << mapArr[y - 1][x];
			mapArr[y][x] = mapArr[y - 1][x];
		}
}

void Game::updateScoreAndCount() {
	// just updating the score and Shapes count.
	gotoxy(32, 1);
	cout << "              ";
	gotoxy(32, 1);
	cout << gameScore;
	gotoxy(36, 2);
	cout << shapeCount;
}

bool Game::gameOver() {
	for (int i = 0; i < WIDTH + 1; i++)
		if (mapArr[0][i] != ' ') {
			gotoxy(2, HEIGHT + 1);
			cout << "Game Over" << endl << endl;
			return true;
		}
	return false;
}

void Game::startNewGame() {

	//init the game settings.
	gameScore = 0;
	shapeCount = 0;
	int hitShapeCounter = 0;
	speedSaver = gameSpeed = 300;
	initBoard();
	initMenu();
	updateScoreAndCount();
	while (!gameOver()) {
		hitShapeCounter = 0;
		Shape* s1 = dropNewShape(); //create new shape and drop it, shape is now s1.
		hitShapeCounter = s1->createExplotion(mapArr);
		gameScore = gameScore - (50 * hitShapeCounter);
		updateScoreAndCount();
		shapeCount++;


		if (s1->getType() != Shape::bomb)
			for (int i = 0; i < 4; i++) //put the shape in the map array of the game 
				mapArr[s1->getShapeArr()[i].getY()][s1->getShapeArr()[i].getX()] = s1->getShapeArr()[i].getType();

		updateBoard();
		updateLineComplition(s1);
	}
}

int Game::keyPressed(int keyCode,Shape* s1) {

	switch (keyCode)
	{

	case NewGame: // '1' ->Start new game.
	{
		startNewGame();
		break;
	}

	case pauseGame: // '2' -> pause Game
	{
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

	case slowDown: // '3' -> slow down game
	{
		gameSpeed *= 1.3;
		speedSaver = gameSpeed;
		break;
	}
	case speedUp: // '4' -> speed up game
	{
		gameSpeed *= 0.7;
		speedSaver = gameSpeed;
		break;
	}

	case exitGame: // '9' -> exit game
	{
		exit(0);
		break;
	}

	case downArrow: {
		gameSpeed = gameSpeed / 10;
	}

	default: {
		return s1->moveShape(keyCode,mapArr);
		break;
	}

	}

	return 0;
}

void Game::updateBoard() {
	//this function print the shapes
	for (int y = 0; y < HEIGHT; y++)
		for (int x = 1; x < WIDTH + 1; x++) {
			gotoxy(x, y);
			cout << mapArr[y][x];
		}
}

Shape* Game::createRandomShape() {
	srand((unsigned int)time(NULL));
	int pivot = rand() % 7; //create random number 0-6

	Shape* b1 = new Bomb;
	Shape* j1 = new Joker;
	Shape* s1 = new Shape(Shape::line);
	Shape* s2 = new Shape(Shape::cube);
	Shape* s3 = new Shape(Shape::Lshape);
	Shape* s4 = new Shape(Shape::PlusShape);
	Shape* s5 = new Shape(Shape::ZShape);


	Shape* pShapes[7] = {b1,j1,s1,s2,s3,s4,s5 };

	return pShapes[pivot];

}

void Game::updateLineComplition(Shape* s1) {
	bool completedLine;
	int numOfLinesComplted = 0;

	//for each point in the shape, check if she complted a line :
	for (int i = 0; i < HEIGHT; i++) { // need to start from the top to bottom.
		completedLine = true; //we assume that the line is complted.
		for (int j = 1; j < WIDTH + 1; j++) {
			if (mapArr[i][j] == ' ') //that's mean that the line isn't complted.
				completedLine = false; //--Maybe add here a break;.
		}
		if (completedLine) {
			numOfLinesComplted++;
			updateCompltedLine(i); //this update the board and move above shapes down.
		}
	}
	if (s1->getType() == Shape::joker && numOfLinesComplted == 1) { //in case the line complted by a joker.
		gameScore += 50;
	}
	else switch (numOfLinesComplted)
	{
	case 1: {
  		gameScore += 100;
		break;
	}
	case 2: {
		gameScore += 300;
		break;
	}
	case 3: {
		gameScore += 500;
		break;
	}
	case 4: {
		gameScore += 800;
		break;
	}
	default:
		break;
	}



	updateScoreAndCount();
}
