#include "Playing.h"
#include "drawing.h"
#include <Windows.h>
#include <cstdlib>
#include <thread>
#include <ctime>
Playing::Playing()
{
	
}

void Playing::multiThreading() {



}
void Playing::cls() {
	system("cls");
	_gotoxy(xpos, ypos);
	drawPlayer(xpos, ypos);
}

void Playing::SetDropX() {
	srand((unsigned int)time(NULL));
	dropX = rand() % 119 +1;
}

void Playing::Up() {
	if (ypos > 26)
		ypos -= 1;
	else
		ypos = 26;
	drawPlayer(xpos, ypos);
}

void Playing::Left() {
	if (xpos >= 1)
		xpos -= 1;
	else
		xpos = 0;
	drawPlayer(xpos, ypos);
}

void Playing::Down() {
	if (ypos < 40)
		ypos += 1;
	else
		ypos = 40;
	drawPlayer(xpos, ypos);
}

void Playing::Right() {
	if (xpos < 120)
		xpos += 1;
	else
		xpos = 120;
	drawPlayer(xpos, ypos);
}

void Playing::drawPlayer(int xpos, int ypos) {

	if (check) {
		for (int i = 0; i <= 2; i++) {
			_gotoxy(temp[i][0], temp[i][1]);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x11);
			cout << ' ';
		}
	}
	
	for (int i = xpos -1 ; i <= xpos + 1; i++) {
			temp[xpos - i - 1][0] = i;
			temp[xpos - i - 1][1] = ypos;
			_gotoxy(i, ypos);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
			cout << 'A';
				
				check = true;
	}
	
}
 
void Playing::reset() {
	xpos = 60;
	ypos = 40;
}

void Playing::DropNote() {
	SetDropX();

	for (int i = 1; i < 41; i++) {
		if (i != 40) {
			_gotoxy(dropX, i);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x44);
			cout << ' ';
			_gotoxy(dropX + 1, i);
			cout << ' ';
			_gotoxy(dropX + 2, i);
			cout << ' ';
			Sleep(10);
		}
		
		if (i != 1) {
			_gotoxy(dropX, i-1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x11);
			cout << ' ';
			_gotoxy(dropX + 1, i-1);
			cout << ' ';
			_gotoxy(dropX + 2, i - 1);
			cout << ' ';
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	



	
}

Playing::~Playing()
{
}
