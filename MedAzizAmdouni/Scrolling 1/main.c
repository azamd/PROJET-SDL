#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scroll.h"

int main()
{
SDL_Surface *screen=NULL;
SDL_Surface *imgfond=NULL;

int running=1;
SDL_Rect posfond;

SDL_Init(SDL_INIT_VIDEO);

    screen = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    
    SDL_WM_SetCaption("SCROLLING", NULL);  
 
 scrolling(screen,imgfond ,running, posfond);


SDL_FreeSurface(imgfond);
 SDL_Quit();

    return EXIT_SUCCESS;
}
