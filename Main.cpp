/************************************************************************************************
	Name: CoachLDE
	Date: 10.10.2023
	Purpose: This will be the beginnings of how I implement the function to take in user input
			 and move a character based on that user input.  In this example I will use the
			 GetAsyncKeyState() function.  Today I will introduce a while loop
			 which is common in gameing.  A While Loop keeps the prgram/game running until a
			 certain condition is met that will close the program.
*************************************************************************************************/

#include <iostream>
#include <Windows.h>	//In this library is the function that will allow is to control cursor position
#include <conio.h>		//In this library is a function to detect keypresses

using namespace std;

void GoToXY(int x, int y)
{
	HANDLE conHandle;	//Variable to hold the console handle
	conHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;		//Variable of the type/struct COORD/COORDINATE that holds the X and Y positions
	coord.X = x;
	coord.Y = y;
	//Takes two parameters.  The ID of the console window and Structure of the type COORD which are the coordinates where
	//we want to position the cursor
	SetConsoleCursorPosition(conHandle, coord);
}

int main()
{
	bool gameOver = false;

	int x = 10;
	int y = 10;

	GoToXY(x, y);		//At the initial position draw a star
	cout << '*';

	while (!gameOver)
	{
		char key = _getch();
		GoToXY(x, y); cout << " ";	//With each loop we will erase where the star was
		if (GetAsyncKeyState(VK_LEFT)) x--;
		if (GetAsyncKeyState(VK_RIGHT)) x++;
		if (GetAsyncKeyState(VK_UP)) y--;
		if (GetAsyncKeyState(VK_DOWN)) y++;
		if (GetAsyncKeyState(VK_ESCAPE)) y++;
		GoToXY(x, y); cout << "*";	//With each loop we will draw where the star is
	}

	return 0;
}