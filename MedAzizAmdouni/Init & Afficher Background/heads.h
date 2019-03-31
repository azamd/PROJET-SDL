#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#include <SDL/SDL.h>


 SDL_Surface * Init_Background(SDL_Surface *backg, SDL_Rect *backg_rect ,int x,int y);
 void Afficher_Background(SDL_Surface *backg , SDL_Surface *screen , SDL_Rect backg_rect );


#endif // JEU_H_INCLUDED
