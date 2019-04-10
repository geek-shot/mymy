#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <string.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

//int  main()
void chrono()
{
  char chrono[16];
  SDL_Event event;
  TTF_Font *police;
  Uint32 t1, t2, ok = 1;
  SDL_Surface *ecran = NULL, *texte =  NULL;
  SDL_Color noir = {255,255,180,0}, rouge = {100,0,0};
 
  SDL_Init(SDL_INIT_VIDEO);
  ecran = SDL_SetVideoMode(920, 644, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
 //SDL_WM_SetCaption("Timee", 0);
  TTF_Init();
  police = TTF_OpenFont("stocky.ttf", 50);
  t1 = SDL_GetTicks();
 
  while(ok){
    SDL_PollEvent(&event);
 	switch(event.type)
            {
                case SDL_QUIT:
                    ok = 0;
                case SDL_KEYUP:
                	switch(event.key.keysym.sym)
                	{
                		case SDLK_ESCAPE:
                			ok = 0;
                			break;
                	}
                                    break;
            }

    t2 = SDL_GetTicks() - t1;         //Minute       //Seconde   //Dixieme
    sprintf(chrono, "%02u:%02u.%u", t2/1000/60%60, t2/1000%60, t2%1000/100);
    texte = TTF_RenderText_Shaded(police, chrono, rouge,noir);
 
    SDL_BlitSurface(texte, NULL, ecran, 0);
    SDL_Flip(ecran);
    SDL_Delay(10);
  }
 


 //return 0;
}

