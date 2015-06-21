#ifndef CONSOLE_H
#define CONSOLE_H
#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>
#include <Windows.h> 
#include <conio.h> 
#include "Playing.h"
#include "drawing.h"
#include <thread>

inline void keyInput(Playing* p) {

	bool con = true;
	while (con)
	{
		int Keys = 0;
		fflush(stdin);
		switch (Keys = _getch()) {
		case 72:
			p->Up();

			break; // Up arrow
		case 77:

			p->Right();

			break; // Right arrow
		case 75:

			p->Left();

			break; //Left arrow
		case 80:

			p->Down();

			break; // Down arrow


			break;


		case '\033':
			con = false;


			break;

		}

	}
}


inline void drawWhite(int x, int y) {
	_gotoxy(x, y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	cout << ' ';
}

inline void howToPlay() {
	system("cls");
	for (int i = 14; i < 14 + 90; i++) {
		drawWhite(i, 2); drawWhite(i, 3);
		drawWhite(i, 16); drawWhite(i, 17);
	}
	for (int i = 4; i < 16; i++) {
		drawWhite(14, i); drawWhite(15, i);
		drawWhite(102, i); drawWhite(103, i);
	}

	for (int i = 6; i < 14; i++) {
		drawWhite(18, i); drawWhite(19, i);
		drawWhite(26, i); drawWhite(27, i);
		drawWhite(42, i); drawWhite(43, i);
		drawWhite(60, i); drawWhite(61, i);
		drawWhite(71, i); drawWhite(72, i);
	}

	for (int i = 20; i < 26; i++) {
		drawWhite(i, 12); drawWhite(i, 13);
	}

	for (int i = 30; i < 40; i++) {
		drawWhite(i, 6); drawWhite(i, 7);
		drawWhite(i, 9); drawWhite(i, 10);
		drawWhite(i, 12); drawWhite(i, 13);
		drawWhite(i + 12, 6); drawWhite(i + 12, 7);
		drawWhite(i + 12, 9); drawWhite(i + 12, 10);
		drawWhite(i + 12, 12); drawWhite(i + 12, 13);
		drawWhite(i + 49, 9); drawWhite(i + 49, 10);
		drawWhite(i + 60, 9); drawWhite(i + 60, 10);
	}
	{
		drawWhite(30, 8); drawWhite(31, 8);
		drawWhite(38, 11); drawWhite(39, 11);
		drawWhite(56, 10); drawWhite(57, 10);
		drawWhite(56, 11); drawWhite(57, 11);
		drawWhite(58, 8); drawWhite(59, 8);
		drawWhite(58, 9); drawWhite(59, 9);
		drawWhite(64, 10); drawWhite(65, 10);
		drawWhite(64, 11); drawWhite(65, 11);
		drawWhite(62, 8); drawWhite(63, 8);
		drawWhite(62, 9); drawWhite(63, 9);
		drawWhite(67, 8); drawWhite(68, 8);
		drawWhite(67, 9); drawWhite(68, 9);
		drawWhite(75, 8); drawWhite(76, 8);
		drawWhite(75, 9); drawWhite(76, 9);
		drawWhite(69, 10); drawWhite(70, 10);
		drawWhite(69, 11); drawWhite(70, 11);
		drawWhite(73, 10); drawWhite(74, 10);
		drawWhite(73, 11); drawWhite(74, 11);
		drawWhite(81, 8); drawWhite(82, 8);
		drawWhite(83, 7); drawWhite(84, 7);
		drawWhite(81, 11); drawWhite(82, 11);
		drawWhite(83, 12); drawWhite(84, 12);
		drawWhite(96, 11); drawWhite(97, 11);
		drawWhite(94, 12); drawWhite(95, 12);
		drawWhite(96, 8); drawWhite(97, 8);
		drawWhite(94, 7); drawWhite(95, 7);
	}	

	_gotoxy(50, 24);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x1F);
	cout << "Press Esc to back";

	int def_x = 50;
	int def_y = 24;
	Playing p;
	
	thread t(&keyInput, &p);
	thread t2(&DropNoteX,0, &def_x, &def_y,52);
	t.join(); t2.join();

}

struct console
{
	console(unsigned width, unsigned height)
	{
		SMALL_RECT r;
		COORD      c;
		hConOut = GetStdHandle(STD_OUTPUT_HANDLE);
		if (!GetConsoleScreenBufferInfo(hConOut, &csbi))
			throw runtime_error("You must be attached to a human.");

		r.Left =
			r.Top = 0;
		r.Right = width - 1;
		r.Bottom = height - 1;
		SetConsoleWindowInfo(hConOut, TRUE, &r);

		c.X = width;
		c.Y = height;
		SetConsoleScreenBufferSize(hConOut, c);
	}

	~console()
	{
		SetConsoleTextAttribute(hConOut, csbi.wAttributes);
		SetConsoleScreenBufferSize(hConOut, csbi.dwSize);
		SetConsoleWindowInfo(hConOut, TRUE, &csbi.srWindow);
	}

	inline void color(WORD color = 0x07)
	{
		SetConsoleTextAttribute(hConOut, color);
	}

	HANDLE                     hConOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
};

inline void switchMenu(int* ypos, int* pState, bool* cont, Playing* pPlay) {
	if (*ypos == 32) {
		*pState = 2;
		pPlay->reset();
		pPlay->cls();
	}
	else if (*ypos == 34) {
		*pState = 1;
		howToPlay();

	}
	else if (*ypos == 36) {
		system("cls");
		drawTail();
		system("cls");
		_gotoxy(56, 19);
		cout << "BYE BYE";
		Sleep(1000);
		*cont = false;
	}
		}

#endif