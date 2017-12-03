#include <iostream>
using namespace std;

#include <windows.h>
#include <process.h>

void gotoxy(int, int); // prototype

// function definition
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	cout.flush();
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}

char whiteSquare = 254;

void main() {
	cout << whiteSquare << endl;
}