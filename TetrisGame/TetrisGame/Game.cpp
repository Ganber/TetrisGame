#include <ctime>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include "Game.h"

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

Shape Game::dropNewShape() {
	char keyprees;
	Shape s1(createRandomShape()); //create a random shape.
	s1.draw();

	clock_t startTime = clock(); //Start timer for speed.
	double msPassed;

	while (s1.isShapeCanMove(Point::DOWN, mapArr)) {
		msPassed = ((clock() - startTime)); //miliSecond passed..

		if (_kbhit()) {
			keyprees = _getch();
			if (s1.getType() == Shape::joker && keyprees == 's')
				break;
			else
				if (!keyPressed(keyprees, s1)) //if this return false, that's mean we have a bomb explotion.
					break; 
		}

		if (msPassed > gameSpeed) { // every 'gameSpeed' ms move down shape.
			for (int i = 0; i < 4; i++) {
				if (s1.getShapeArr()[i].getType() != ' ')
					s1.getShapeArr()[i].move(Point::DOWN, mapArr);

				if (s1.getType() != Shape::bomb) {
					gameScore += int(80 / gameSpeed);
				}
				updateScoreAndCount();
			}
			msPassed = 0; //starting the timer again.
			startTime = clock();
			Sleep(1);
		}
	}


	//this is for giving the player one last movment before the shape is stopped.
	msPassed = 0;
	while (msPassed <= gameSpeed) {
		if (_kbhit()) {
			keyPressed(_getch(), s1);
		}
		msPassed = ((clock() - startTime)); //miliSecond passed..
	}


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
	speedSaver = gameSpeed = 300;
	initBoard();
	initMenu();
	updateScoreAndCount();
	while (!gameOver()) {
		Shape s1 = dropNewShape(); //create new shape and drop it, shape is now s1.

		shapeCount++;

		if (s1.getType() == Shape::bomb)
			createExplosion(s1);

		else
			for (int i = 0; i < 4; i++) //put the shape in the map array of the game 
				mapArr[s1.getShapeArr()[i].getY()][s1.getShapeArr()[i].getX()] = s1.getShapeArr()[i].getType();

		updateLineComplition(s1);
	}
}

bool Game::keyPressed(int keyCode, Shape &s1) {

	switch (keyCode)
	{
	case 75: // left Arrow 
	{ 
		if (s1.getType() == Shape::bomb) { // this is for side bombing
			if (s1.getShapeArr()[0].getX() > 0)
				if (mapArr[s1.getShapeArr()[0].getY()][s1.getShapeArr()[0].getX() - 1] != ' ') {
				createExplosion(s1);
				return false;
				}
		}

		 if (s1.isShapeCanMove(Point::LEFT, mapArr))
			for (int i = 0; i < 4; i++)
				s1.getShapeArr()[i].move(Point::LEFT, mapArr);
		break;
	}
	case 77: // right arrow
	{
		if (s1.getType() == Shape::bomb) { //this is for side bombing.
			if (s1.getShapeArr()[0].getX() <= WIDTH)
				if (mapArr[s1.getShapeArr()[0].getY()][s1.getShapeArr()[0].getX() + 1] != ' ') {
					createExplosion(s1);
					return false;
				}
		}

		if (s1.isShapeCanMove(Point::RIGHT, mapArr))
			for (int i = 0; i < 4; i++)
				s1.getShapeArr()[3 - i].move(Point::RIGHT, mapArr);
		break;
	}

	case 80: // down arrow
	{
		if (!isPressedDown)
			speedSaver = gameSpeed;

		if (gameSpeed > 50) {
			gameSpeed = gameSpeed / 10;
			isPressedDown = true;
		}
		break;
	}

	case 32: // Space key
	{
		if (s1.getType() == Shape::line)
			s1.rotate();
		break;
	}

	case 49: // '1' ->Start new game.
	{
		startNewGame();
		break;
	}

	case 50: // '2' -> pause Game
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

	case 51: // '3' -> slow down game
	{
		gameSpeed *= 1.3;
		speedSaver = gameSpeed;
		break;
	}
	case 52: // '4' -> speed up game
	{
		gameSpeed *= 0.7;
		speedSaver = gameSpeed;
		break;
	}

	case 57: // '9' -> exit game
	{
		exit(0);
		break;
	}


	default: {
		break;
	}

	}
	return true;
}

void Game::createExplosion(Shape bomb) {
	int hitShapeCounter = 0;

	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			int y = bomb.getShapeArr()[0].getY() + i; //the y value of the bomb +i
			int x = bomb.getShapeArr()[0].getX() + j; //the x value of the bomb +j
			if (y < Game::HEIGHT && x > 0 && x <= Game::WIDTH)
				if (mapArr[y][x] != ' ') {
					mapArr[y][x] = ' ';
					hitShapeCounter++;
				}
		}
	}

	updateBoard();
	gameScore = gameScore - (50 * hitShapeCounter);
}

void Game::updateBoard() {
	//this function print the shapes
	for (int y = 0; y < HEIGHT; y++)
		for (int x = 1; x < WIDTH + 1; x++) {
			gotoxy(x, y);
			cout << mapArr[y][x];
		}
}

int Game::createRandomShape() {
	srand((unsigned int)time(NULL));

	int pivot = rand() % 10 + 1; //create random number 1-10

	if (pivot == 1) // 10% for bomb
		return Shape::bomb;

	else if (pivot == 2) // 10% for joker
		return Shape::joker;

	else if (pivot > 2 && pivot < 7) //40% for cube.
		return Shape::cube;

	else
		return Shape::line; // 40% for line.
}

void Game::updateLineComplition(Shape &s1) {
	bool completedLine;
	int numOfLinesComplted = 0;

	//for each point in the shape, check if she complted a line :
	for (int i = 3; i >= 0; i--) { // need to start from the top to bottom.
		completedLine = true; //we assume that the line is complted.
		for (int j = 1; j < WIDTH + 1; j++) {
			if (mapArr[s1.getShapeArr()[i].getY()][j] == ' ') //that's mean that the line isn't complted.
				completedLine = false; //--Maybe add here a break;.
		}
		if (completedLine) {
			numOfLinesComplted++;
			updateCompltedLine(s1.getShapeArr()[i].getY()); //this update the board and move above shapes down.
		}
	}
	if (s1.getType() == Shape::joker && numOfLinesComplted == 1) { //in case the line complted by a joker.
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