#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include "deplacment.h"




int main ()
{
int continuer=1 ;

SDL_Surface *ecran =NULL;
SDL_Surface *imageFond=NULL ;
SDL_Surface *personage=NULL;
SDL_Rect positionDuFond ;
SDL_Rect positionPerso ;


SDL_Init (SDL_INIT_VIDEO);

ecran= SDL_SetVideoMode(667,250,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("Deplacer un personage",NULL);

deplacment (ecran,imageFond,personage,positionDuFond,positionPerso ,continuer);

SDL_FreeSurface(personage);
SDL_FreeSurface(imageFond);
SDL_Quit();
return EXIT_SUCCESS;
}


