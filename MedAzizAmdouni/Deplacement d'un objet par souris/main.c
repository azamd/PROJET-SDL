#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include "dep.h"

int main()
{
SDL_Surface *screen=NULL;
SDL_Surface *img=NULL;
int running=1;

SDL_Rect pos;
pos.x=0;
pos.y=0;

SDL_Init(SDL_INIT_VIDEO);

    screen = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Deplacement d'un objet par souris", NULL);  
    img= IMG_Load("box.png");

while(running)
{
SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));

translation(screen,img,running,pos);

SDL_Flip(screen);
}



SDL_FreeSurface(img);
 SDL_Quit();

    return EXIT_SUCCESS;
}
