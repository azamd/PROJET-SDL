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


typedef struct{
	SDL_Surface *tab[3];
	SDL_Rect pos;
	int frame;
}Perso;


typedef struct{
	int haut, bas, droite, gauche;
}Input;


#endif