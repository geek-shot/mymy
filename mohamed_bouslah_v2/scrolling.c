#include "scrolling.h"

void right(Background *back)
{
	back->backgroundPos.x -= 5;
	if(back->backgroundPos.x < 0)
	{
		back->backgroundPos.x = 0;
	}
}

void left(Background *back)
{
	back->backgroundPos.x += 5;
	if(back->backgroundPos.x > back->backgroundImg->w)
	{
		back->backgroundPos.x = back->backgroundImg->w;
	}
}
