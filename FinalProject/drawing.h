#ifndef DRAWING_H
#define DRAWING_H

#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>
#include <Windows.h>
#include "main.h"

using namespace std;

void _gotoxy(int x, int y);
void _gotoxy(int* x, int* y);
inline void changeCursorPosition(int* poz_x, int* poz_y, bool upDown) {
	cout << ' ';
	_gotoxy(poz_x, poz_y);
	if (upDown) {
		if (*poz_y == 32)
			*poz_y = 36;
		else if (*poz_y == 34)
			*poz_y = 32;
		else if (*poz_y == 36)
			*poz_y = 34;
	}
	else {
		if (*poz_y == 32)
			*poz_y = 34;
		else if (*poz_y == 34)
			*poz_y = 36;
		else if (*poz_y == 36)
			*poz_y = 32;
	}
	_gotoxy(poz_x, poz_y);
	cout << '*';
	_gotoxy(poz_x, poz_y);
}
void drawBg();
void drawMain();
void drawTail();
void DropNote(int sleep, int* x, int* y);
void DropNoteX(int sleep, int* x, int* y, int whereX);

#endif DRAWING_H