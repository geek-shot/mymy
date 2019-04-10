#include "score.h"

void loadFont()
{
	font = TTF_OpenFont("angelina.TTF", 56);
	if (font == NULL)
        {
		printf("Can not to open Font : %s\n", TTF_GetError());
		exit(1);
	}
}
/**
* @brief closeFont
* @return Nothing
*/
void closeFont()
{
	if (font != NULL)
        {
		TTF_CloseFont(font);
	}
}
/**
* @brief initElements
* @return Nothing
*/
void calculate(int *score)
{
	if (player.x>Enemie.x+20)
        {
		*score += 5;
	}
if ((player.x==0)||(player.y==0))
{ *score=0;
}
}


/**
* @brief DrawScore
* @param screen the screen
* @param score score
* @return Nothing
*/

void DrawScore(SDL_Surface *screen, int score)
{
        char actualScore[100];
        SDL_Color color;
        color.r = 255 ;
        color.g = 255 ;
        color.b = 255 ;
        sprintf (actualScore,"%d",score);
        SDL_Rect pospoints;
        pospoints.x=600;
        pospoints.y=30;
        game.points = TTF_RenderText_Blended(font,actualScore,color);
        SDL_BlitSurface	(game.points,NULL,screen,&pospoints);
}
void drawGameOver(SDL_Surface *screen)
{
TTF_Font *font;
font = TTF_OpenFont("angelina.TTF", 56);
        SDL_Color color;
        color.r = 213 ;
        color.g = 4 ;
        color.b = 20 ;
        char gameOver[100];
        SDL_Rect posgameOver;
        posgameOver.x=200;
        posgameOver.y=200;
        strcpy (gameOver,"GAME OVER");
        game.gameOver = TTF_RenderText_Blended(font,gameOver,color);
        SDL_BlitSurface	(game.gameOver,NULL,screen,&posgameOver);

}

void drawWin(SDL_Surface *screen)
{
TTF_Font *font;
font = TTF_OpenFont("angelina.TTF", 56);
        SDL_Color color;
        color.r = 213 ;
        color.g = 4 ;
        color.b = 20 ;
        char gameOver[100];
        SDL_Rect posgameOver;
        posgameOver.x=200;
        posgameOver.y=200;
        strcpy (gameOver,"LEVEL 1 COMPLETED");
        game.gameOver = TTF_RenderText_Blended(font,gameOver,color);
        SDL_BlitSurface	(game.gameOver,NULL,screen,&posgameOver);

}


