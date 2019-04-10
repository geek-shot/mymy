#include "scrolling.h"

void al_limin(Background *back)
{
	back->backgroundPos.x -= 5;
	if(back->backgroundPos.x < 0)
	{
		back->backgroundPos.x = 0;
	}
}

void al_lisar(Background *back)
{
	back->backgroundPos.x += 5;
	if(back->backgroundPos.x > back->backgroundImg->w)
	{
		back->backgroundPos.x = back->backgroundImg->w;
	}
}
