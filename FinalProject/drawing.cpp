#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>
#include <Windows.h>
#include "drawing.h"
#include "console.h"
#include "main.h"

using namespace std;

// we can draw 40 lines and 119 char per line
 const int _maxWidth = 119;
 
// Screen divide depth
 const int _divDepth = 4;

 void _gotoxy(int x, int y) {
	 static HANDLE h = NULL;
	 if (!h)
		 h = GetStdHandle(STD_OUTPUT_HANDLE);
	 COORD c = { x, y };
	 SetConsoleCursorPosition(h, c);
 }

void _gotoxy(int* x, int* y) {
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { *x, *y };
	SetConsoleCursorPosition(h, c);
}

void drawBg(console& mainCon) {
	string line[40];
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | FOREGROUND_INTENSITY);
	system("cls");
	for (int i = 0; i < 40; i++) {
		line[i].assign(_maxWidth, ' ');
		if (i != 39) {
			cout << line[i] << endl;
		}
		else {
			cout << line[i] << flush;
		}
	}

		}

void drawMain() {
	system("cls");
	string line[40];

	for (int i = 0; i < 2; i++) {
		int BackColorFill = _maxWidth - (_maxWidth/_divDepth)- (_maxWidth/(_divDepth*_divDepth));
		int WhiteColorFill = _maxWidth - BackColorFill;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x11);
		line[i].assign(BackColorFill, ' ');
		cout << line[i];
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xFF);
		line[i].assign(WhiteColorFill, ' ');
		cout << line[i] << endl;	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x11);

	}

	for (int i = 2; i < 4; i++) {
		int FrontBackColorFill = _maxWidth - (_maxWidth / _divDepth)*2 - (_maxWidth / (_divDepth*_divDepth));
		int LastBackColorFill = _maxWidth / _divDepth;
		int WhiteColorFill = _maxWidth - FrontBackColorFill - LastBackColorFill;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x11);
		line[i].assign(FrontBackColorFill, ' ');
		cout << line[i];
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
		line[i].assign(WhiteColorFill, ' ');
		cout << line[i] ;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x11);
		line[i].assign(LastBackColorFill, ' ');
		cout << line[i] <<endl;
	}

	for (int i = 4; i < 6; i++) {
		int FrontBackColorFill = _maxWidth - (_maxWidth / _divDepth) *3 - (_maxWidth / (_divDepth*_divDepth));
		int LastBackColorFill = (_maxWidth / _divDepth)*2;
		int WhiteColorFill = _maxWidth - FrontBackColorFill - LastBackColorFill;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x11);
		line[i].assign(FrontBackColorFill, ' ');
		cout << line[i];
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
		line[i].assign(WhiteColorFill, ' ');
		cout << line[i];
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x11);
		line[i].assign(LastBackColorFill, ' ');
		cout << line[i] << endl;
	}

	for (int i = 6; i < 8; i++) {
		int BackColorFill = _maxWidth - (_maxWidth / _divDepth);
		int WhiteColorFill = _maxWidth - BackColorFill;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
		line[i].assign(WhiteColorFill, ' ');
		cout << line[i];
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x11);
		line[i].assign(BackColorFill, ' ');
		cout << line[i] << endl;
	}
	
	for (int i = 8; i < 10; i++) {
		int FrontBackColorFill = _maxWidth - (_maxWidth / _divDepth) ;
		int LastBackColorFill = 0;
		int YellowColorFill = _maxWidth - FrontBackColorFill - LastBackColorFill;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x11);
		line[i].assign(FrontBackColorFill, ' ');
		cout << line[i];
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xEE);
		line[i].assign(YellowColorFill, ' ');
		cout << line[i];
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x11);
		line[i].assign(LastBackColorFill, ' ');
		cout << line[i] << endl;
	}

	for (int i = 10; i < 12; i++) {
		int FrontBackColorFill = _maxWidth - (_maxWidth / _divDepth)*2;
		int LastBackColorFill = _maxWidth / _divDepth + (_maxWidth / (_divDepth*_divDepth));
		int YellowColorFill = _maxWidth - FrontBackColorFill - LastBackColorFill;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x11);
		line[i].assign(FrontBackColorFill, ' ');
		cout << line[i];
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xEE);
		line[i].assign(YellowColorFill, ' ');
		cout << line[i];
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x11);
		line[i].assign(LastBackColorFill, ' ');
		cout << line[i] << endl;
	}

	for (int i = 12; i < 14; i++) {
		int FrontBackColorFill = _maxWidth - (_maxWidth / _divDepth)*3 ;
		int LastBackColorFill = (_maxWidth / _divDepth)*2 + (_maxWidth / (_divDepth*_divDepth));
		int YellowColorFill = _maxWidth - FrontBackColorFill - LastBackColorFill;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x11);
		line[i].assign(FrontBackColorFill, ' ');
		cout << line[i];
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xEE);
		line[i].assign(YellowColorFill, ' ');
		cout << line[i];
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x11);
		line[i].assign(LastBackColorFill, ' ');
		cout << line[i] << endl;

	}

	for (int i = 14; i < 16; i++) {
		int FrontBackColorFill = 0;
		int LastBackColorFill = (_maxWidth / _divDepth)*3 + (_maxWidth / (_divDepth*_divDepth));
		int YellowColorFill = _maxWidth - FrontBackColorFill - LastBackColorFill;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x11);
		line[i].assign(FrontBackColorFill, ' ');
		cout << line[i];
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xEE);
		line[i].assign(YellowColorFill, ' ');
		cout << line[i];
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x11);
		line[i].assign(LastBackColorFill, ' ');
		cout << line[i] << endl;
	}

	for (int i = 16; i < 18; i++) {
		int BackColorFill = _maxWidth - (_maxWidth / _divDepth) - (_maxWidth / (_divDepth*_divDepth));
		int WhiteColorFill = _maxWidth - BackColorFill;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x11);
		line[i].assign(BackColorFill, ' ');
		cout << line[i];
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
		line[i].assign(WhiteColorFill, ' ');
		cout << line[i] << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x11);

	}

	for (int i = 18; i < 20; i++) {
		int FrontBackColorFill = _maxWidth - (_maxWidth / _divDepth) * 2 - (_maxWidth / (_divDepth*_divDepth));
		int LastBackColorFill = _maxWidth / _divDepth;
		int WhiteColorFill = _maxWidth - FrontBackColorFill - LastBackColorFill;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x11);
		line[i].assign(FrontBackColorFill, ' ');
		cout << line[i];
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
		line[i].assign(WhiteColorFill, ' ');
		cout << line[i];
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x11);
		line[i].assign(LastBackColorFill, ' ');
		cout << line[i] << endl;
	}

	for (int i = 20; i < 22; i++) {
		int FrontBackColorFill = _maxWidth - (_maxWidth / _divDepth) * 3 - (_maxWidth / (_divDepth*_divDepth));
		int LastBackColorFill = (_maxWidth / _divDepth) * 2;
		int WhiteColorFill = _maxWidth - FrontBackColorFill - LastBackColorFill;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x11);
		line[i].assign(FrontBackColorFill, ' ');
		cout << line[i];
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
		line[i].assign(WhiteColorFill, ' ');
		cout << line[i];
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x11);
		line[i].assign(LastBackColorFill, ' ');
		cout << line[i] << endl;
	}

	for (int i = 22; i < 24; i++) {
		int BackColorFill = _maxWidth - (_maxWidth / _divDepth);
		int WhiteColorFill = _maxWidth - BackColorFill;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
		line[i].assign(WhiteColorFill, ' ');
		cout << line[i];
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x11);
		line[i].assign(BackColorFill, ' ');
		cout << line[i] << endl;
	}
	
	for (int i = 24; i < 40; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x1B);
		line[i].assign(_maxWidth, ' ');
		if (i == 27) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xCF);
			line[i].replace(53, 65, "DO NOT change console size", 27);
			line[i].append(38u, ' ');
		}

		if (i == 32) {
			line[i].replace(53, 65, "1.Game Start",12);
			line[i].append(53u, ' ');
		}
		else if (i == 34) {
			line[i].replace(53, 66, "2.How to Play",13);
			line[i].append(53u, ' ');
		}
		else if (i == 36) {
			line[i].replace(53, 66, "3.Exit", 6);
			line[i].append(60u, ' ');
		}
		else {}
		cout << line[i] << endl;
	}



}

void drawTail() {
	int repeatX = 121;
	int repeatXtemp;
	int repeatY = 40;
	int repeatYtemp;
	int dx = 1;
	int dy = 1;
	int xpos = 0;
	int ypos = 0;
	//int time = timeGetTime();
	while (repeatX != 0) {

		for (repeatXtemp = repeatX; repeatXtemp > 0; repeatXtemp--) {
			_gotoxy(xpos, ypos);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
			cout << ' ';
			xpos += dx;
		}repeatX--; dx *= -1;

		for (repeatYtemp = repeatY; repeatYtemp > 0; repeatYtemp--) {
			_gotoxy(xpos, ypos);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
			cout << ' ';
			ypos += dy;
		}repeatY--; dy *= -1;

	}
}

void DropNote(int sleep, int* x, int* y) {

	Sleep(sleep);

	Playing p;
	p.SetDropX();
	int dropx = p.dropX;
	for (int i = 1; i < 41; i++) {
		if (i != 40) {
			_gotoxy(dropx, i);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x44);
			cout << ' ';
			_gotoxy(dropx + 1, i);
			cout << ' ';
			_gotoxy(dropx + 2, i);
			cout << ' ';
			Sleep(50);
		}

		if ((*x == dropx || *x == dropx-1 || *x == dropx+1) && (*y == i || *y == i -1 || *y == i+1)) {
			
			system("cls");
			drawMain();
			return;
		}

		if (i != 1) {
			_gotoxy(dropx, i - 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x11);
			cout << ' ';
			_gotoxy(dropx + 1, i - 1);
			cout << ' ';
			_gotoxy(dropx + 2, i - 1);
			cout << ' ';
			_gotoxy(dropx + 3, i - 1);
			cout << ' ';
			_gotoxy(dropx + 4, i - 1);
			cout << ' ';
			_gotoxy(dropx + 5, i - 1);
			cout << ' ';
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);

}

void DropNoteX(int sleep, int* x, int* y, int whereX) {

	Sleep(sleep);

	int dropx = whereX;
	for (int i = 1; i < 41; i++) {
		if (i != 40) {
			_gotoxy(dropx, i);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x44);
			cout << ' ';
			_gotoxy(dropx + 1, i);
			cout << ' ';
			_gotoxy(dropx + 2, i);
			cout << ' ';
			_gotoxy(dropx + 3, i);
			cout << ' ';
			_gotoxy(dropx + 4, i);
			cout << ' ';
			_gotoxy(dropx + 5, i);
			cout << ' ';
			Sleep(50);
		}

		if ((*x == dropx || *x == dropx - 1 || *x == dropx + 1) && (*y == i || *y == i - 1 || *y == i + 1)) {



			system("cls");
			drawMain();
			return;
		}

		if (i != 1) {
			_gotoxy(dropx, i - 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x11);
			cout << ' ';
			_gotoxy(dropx + 1, i - 1);
			cout << ' ';
			_gotoxy(dropx + 2, i - 1);
			cout << ' ';
			_gotoxy(dropx + 3, i - 1);
			cout << ' ';
			_gotoxy(dropx + 4, i - 1);
			cout << ' ';
			_gotoxy(dropx + 5, i - 1);
			cout << ' ';

		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);

}