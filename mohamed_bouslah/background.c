#include "background.h"

int loadBackground(Background *Backg)
{
	// load background
	Backg->backgroundImg = IMG_Load("niveau11.png");
	if (Backg->backgroundImg == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return (-1);
	}
	
	
	return (0);
}


void initBackground(Background *Backg)
{
	Backg->backgroundPos.x=0;
	Backg->backgroundPos.y=0;
	Backg->backgroundPos.w=800;
	Backg->backgroundPos.h=600;
}


void blitBackground(Background*Backg,SDL_Surface *screen)
{
	SDL_Rect positionecran;
	positionecran.x=0;
    positionecran.y=0;
	//Blit the bachground to the backbuffer
		SDL_BlitSurface(Backg->backgroundImg, &(Backg->backgroundPos), screen,&positionecran); //scrolling horizontal

}

void freeBackground(Background *Backg)
{
	SDL_FreeSurface(Backg->backgroundImg);
}
