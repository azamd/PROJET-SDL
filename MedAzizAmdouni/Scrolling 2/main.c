#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scrolling.h"

int main()
{
SDL_Surface *screen=NULL;
SDL_Surface *imgfond=NULL;
SDL_Surface *imgperso=NULL;
int running=1;
SDL_Rect posfond;
SDL_Rect positionmilieu;

SDL_Init(SDL_INIT_VIDEO);

    screen = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    
    SDL_WM_SetCaption("SCROLLING+OBJECT", NULL);  
 
 scrolling(screen,imgfond ,imgperso ,running, posfond, positionmilieu);


SDL_FreeSurface(imgfond);
 SDL_Quit();

    return EXIT_SUCCESS;
}
