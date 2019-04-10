#include "structs.h"



/**
* @struct game
* @brief struct for score
*/

struct game
{
	
	SDL_Surface *sante;
	
    SDL_Surface *points;
    SDL_Surface *gameOver;
    SDL_Surface *HUD;
	int isOn;	
};
struct game game;
TTF_Font *font;
extern Input input;
void initElements();
void calculate();
void loadFont();
void closeFont();
void calculate(int *score);
void DrawScore(SDL_Surface *screen, int score);
void DrawVie(SDL_Surface *screen);
void drawGameOver(SDL_Surface *screen);
extern void drawImage(SDL_Surface *image, int x, int y);
void drawGameOver(SDL_Surface *screen);
void chrono(SDL_Surface *ecran);
int score;
extern GameObject player;
extern Enemy Enemie;
void drawWin(SDL_Surface *screen);
Gestion jeu;
