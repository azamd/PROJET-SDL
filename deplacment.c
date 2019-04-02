#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include "deplacment.h"


void deplacment (SDL_Surface *ecran,SDL_Surface *imageFond,SDL_Surface *personage,SDL_Rect positionDuFond,SDL_Rect positionPerso ,int continuer)
{


positionDuFond.x = 0;
positionDuFond.y = 0;

positionPerso.x = 10;
positionPerso.y = 3;

imageFond = IMG_Load ("level1.png");
personage = IMG_Load ("personage.png");
/*SDL_SetColorKey(personage,SDL_SRCCOLORKEY,SDL_MapRGB(personage->format,0,0,255));*/

SDL_BlitSurface(imageFond,NULL,ecran,&positionDuFond);
SDL_BlitSurface(personage,NULL,ecran,&positionPerso);
SDL_Flip(ecran);


SDL_Event event ;
SDL_EnableKeyRepeat(20,20);

while(continuer)
{
SDL_PollEvent(&event);
switch (event.type)
{
case SDL_QUIT:
continuer =0 ;
break;
case SDL_KEYDOWN:
switch (event.key.keysym.sym)
{
case SDLK_UP:
positionPerso.y-=10;
SDL_WaitEvent(&event);
break;
case SDLK_DOWN:
positionPerso.y+=10;
SDL_WaitEvent(&event);
break;
case SDLK_RIGHT:
positionPerso.x+=10;
SDL_WaitEvent(&event);
break;
case SDLK_LEFT:
positionPerso.x-=10;
SDL_WaitEvent(&event);
break;
}
break;


}
SDL_BlitSurface(imageFond,NULL,ecran,&positionDuFond);
SDL_BlitSurface(personage,NULL,ecran,&positionPerso);
SDL_Flip(ecran);
}
}


