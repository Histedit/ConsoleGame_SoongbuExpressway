#include "console.h"
#include "Playing.h"
#include "drawing.h"

void switchMenu(int* ypos) {
	if (*ypos == 32)
		Playing();
	else if (*ypos == 34)
		howToPlay();
}