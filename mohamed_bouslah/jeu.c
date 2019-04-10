#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include"background.h"
#include"scrolling.h"

int main(void)
{
Background back;
loadBackground(&back);
initBackground(&back);

char pause;
SDL_Surface *screen;
SDL_Surface *sprite;
SDL_Rect positionecran;
Mix_Music *musique;
int boucle_jeux=1;

SDL_Event event;


if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Unable to initialize SDL: %s\n",SDL_GetError());
return 1;
}

screen= SDL_SetVideoMode(800,700,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_WM_SetCaption("philia",NULL);
if(screen==NULL)
{
printf("Unable to set video mode: %s\n",SDL_GetError());
return 1;
}

positionecran.x=0;
positionecran.y=0;

if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}
musique=Mix_LoadMUS("philia.mp3");
Mix_PlayMusic(musique, -1);
while(boucle_jeux)
{
	SDL_PollEvent(&event);
	switch(event.type) 
	{
		case SDL_QUIT:
		boucle_jeux = 0;
		break;
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym)
			{
				case SDLK_LEFT:
					al_limin(&back);
				break;
				case SDLK_RIGHT:
					al_lisar(&back);
				break;
			}
		break;
	}


blitBackground(&back,screen);
SDL_Flip(screen);


}
freeBackground(&back);
Mix_FreeMusic(musique);
Mix_CloseAudio();
SDL_Quit();
pause=getchar();
return 0;
}
