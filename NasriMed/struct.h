#ifndef STRUCT
#define STRUCT

#include<SDL/SDL.h>

typedef struct
{
 	SDL_Surface *img;
	SDL_Surface *mask;
	SDL_Rect pos;
	SDL_Rect camera;//la partie à afficher du background (pour le scrolling)

}Background;

typedef struct vie
{
	int nb;
	SDL_Rect position;
	SDL_Rect position2;
	SDL_Surface *heart1;
	SDL_Surface *heart2;
	SDL_Surface *heart3;
	SDL_Surface *heart4;
	SDL_Surface *gameover;
}vie;


typedef struct{
	SDL_Surface *tab[3];
	SDL_Rect pos;
	int frame;
}Perso;


typedef struct{
	int haut, bas, droite, gauche;
}Input;


#endif
