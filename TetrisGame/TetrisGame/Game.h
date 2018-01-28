#ifndef __Game
#define __Game
#include "Shape.h"

class Game {
public:
	enum border { WIDTH = 10, HEIGHT = 15 };
	enum asciiShapes {LongCube=219,TopCube=223};


private:
    double gameSpeed;
	int gameScore;
	int shapeCount;
	char mapArr[HEIGHT][WIDTH + 1] = { false }; // + 1 becuase of the walls.
	double speedSaver; //maybe think about smthing smarted to save speed.
	bool isPressedDown = false; //maybe think about smthing smarted to save speed.

public:
	Game();
	void runGame();
	void initBoard();
	void initMenu();
	Shape* dropNewShape();
	void updateCompltedLine(int line);
	void updateScoreAndCount();
	bool gameOver();
	void startNewGame();
	void keyPressed(int keyCode,Shape* s1);
	void updateBoard();
	Shape* createRandomShape();
	void updateLineComplition(Shape* s1);

};

#endif // !__Game

