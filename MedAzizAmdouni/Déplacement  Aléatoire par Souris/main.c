#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "headers.h"


int main()
{
SDL_Surface * screen=NULL, *imgfond=NULL,*imgperso=NULL;
int x=0,i;

int mousex,mousey;
SDL_Rect posfond ,positionmilieu;

    posfond.x = 0;
    posfond.y = 0;
    posfond.h =1000;
    posfond.w =800;
    positionmilieu.x = 800/ 2 - 50 / 2;
    positionmilieu.y = 420 ;

     SDL_Init(SDL_INIT_VIDEO);

    screen = SDL_SetVideoMode(800,480, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Déplacement par souris avec Scrolling", NULL);

    imgfond = IMG_Load("backg.png");
    imgperso = IMG_Load("box.png");
    
	
  SDL_BlitSurface(imgfond,&posfond,screen, NULL);
  SDL_BlitSurface(imgperso,NULL, screen, &positionmilieu);
  SDL_Flip(screen);
  

    int running = 1;
    SDL_Event event;
    SDL_EnableKeyRepeat(10, 10);
 
    while (running)
    {
        SDL_WaitEvent(&event);

        switch(event.type)
        {
            case SDL_QUIT: 
               running = 0;
                break;
 case SDL_MOUSEBUTTONUP:
             if(event.button.button==SDL_BUTTON_LEFT)
              {mousemove(&positionmilieu,&posfond,imgfond,screen,imgperso);}            
case SDL_KEYDOWN: 
        switch(event.key.keysym.sym)
        {
            case SDLK_RIGHT: 
      moving_right(&positionmilieu,&posfond,imgfond,screen,imgperso);
                break;
            case SDLK_LEFT:
            	moving_left(&positionmilieu,&posfond,imgfond,screen,imgperso);
                break;
case SDLK_UP:
jump(&positionmilieu,&posfond,imgfond,screen,imgperso);
                break;
        }
        break;    
        }

gravity(&positionmilieu,&posfond,imgfond,screen,imgperso);     
   }

   SDL_FreeSurface(imgfond); 
   SDL_Quit();
    return EXIT_SUCCESS;
}
