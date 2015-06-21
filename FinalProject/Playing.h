#ifndef PLAY_H
#define PLAY_H

#include <string>
#include <Windows.h>
#include <cstdlib>
#include <thread>

class Playing
{
public:
	Playing();
	~Playing();
	
	double last_call_time = 0;
	void SetDropX();
	void Up();
	void Left();
	void Down();
	void Right();
	void cls();
	void reset();
	void drawPlayer(int xpos, int ypos);
	void DropNote();
	void multiThreading();
	int dropX;

//	void(Playing::*func)() = DropNote;

private:
	int xpos = 60;
	int ypos = 40;
	int temp[3][2];
	bool check = false;

};

#endif PLAY_H