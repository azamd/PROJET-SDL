#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include "heads.h"

int main()
{
int running=1;
int x=0,y=0;
SDL_Surface *screen= NULL;
SDL_Surface *backg =NULL;
SDL_Rect backg_rect ;
SDL_Event event;

SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode(2000,480,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

 if(screen==NULL){
printf("ERROR! = %s\n",SDL_GetError());
return 1;
}
 
    
backg=Init_Background(backg,&backg_rect ,x,y);

while(running==1)
{

Afficher_Background(backg ,screen,backg_rect ) ;
SDL_Flip(screen);
SDL_WaitEvent(&event);
 switch(event.type)
        {
            case SDL_QUIT:
                running= 0;
                break;}

}
SDL_FreeSurface(backg); 
 
    SDL_Quit();
return 0;
}
