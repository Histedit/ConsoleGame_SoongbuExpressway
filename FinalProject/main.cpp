#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>
#include <Windows.h>
#include <conio.h> 
#include <cstdlib>
#include "drawing.h"
#include "console.h"
#include "main.h"
#include <thread>

using namespace std;

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}


int main() {

	console con(120, 41);
	string str[40];
	void* strarr = &str;	

	bool Continue = TRUE;
	bool* pCont = &Continue;
	ShowConsoleCursor(false);
	//0 = menu, 1=howTo 2=game
	int state = 0;
	int *pState = &state;
	int Keys = 0;
	int poz_x = 51;
	int poz_y = 32;
	int* pPoz_x = &poz_x;
	int* pPoz_y = &poz_y;
	bool pass = false;

	Playing Play = Playing();
	Playing* pPlay = &Play;

	drawMain();
	_gotoxy(pPoz_x, pPoz_y);
	
	system("cls");

	drawMain();
	_gotoxy(pPoz_x, pPoz_y);

	cout << '*';
	_gotoxy(pPoz_x, pPoz_y);

	while (Continue)
	{
			Keys = 0;
		fflush(stdin);
		switch (Keys = _getch()) {
		case 72: 
			if(state == 0) changeCursorPosition(pPoz_x, pPoz_y,true); 
			else if (state == 1 || state == 2) {
				Play.Up();
			}

			break; // Up arrow
		case 77: 
			if (state == 1 || state == 2) {
				Play.Right();
			}
			break; // Right arrow
		case 75:
			if (state == 1 || state == 2) {
				Play.Left();
			}
			break; //Left arrow
		case 80: 
			if (state == 0)
			changeCursorPosition(pPoz_x, pPoz_y, false);
			if (state == 1 || state == 2) {
				Play.Down();
			}
			break; // Down arrow

		case '\r': switchMenu(pPoz_y, pState, pCont, pPlay); 
			if (state == 2) {
				thread t1(&DropNote,0,pPoz_x,pPoz_y);
				thread t2(&keyInput,pPlay);
				thread t3(&DropNote,1200, pPoz_x, pPoz_y);
				thread t4(&DropNote,1400, pPoz_x, pPoz_y);
				thread t5(&DropNote,3000, pPoz_x, pPoz_y);
				thread t8(&DropNoteX, 4000, pPoz_x, pPoz_y,51);
				thread t6(&DropNoteX, 4000, pPoz_x, pPoz_y, 54);
				t1.join(); t2.join(); t3.join(); t4.join(); t5.join(); t6.join(); t8.join();
				
				t1.~thread();	t2.~thread();	t3.~thread();	t4.~thread();
				t5.~thread();	t6.~thread();	t8.~thread();
				state = 0;
				system("cls");
				drawMain();

			}
			break;
		 
		case '\033': 
			if (state == 1 || state ==2) {
				state = 0;
				system("cls");
				drawMain();
				_gotoxy(pPoz_x, pPoz_y);

				cout << '*';
				_gotoxy(pPoz_x, pPoz_y);
			}
			break;

		}
				
	}
	
	return 0;
}