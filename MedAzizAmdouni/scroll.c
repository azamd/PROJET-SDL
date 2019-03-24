#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scroll.h"

void scrolling(SDL_Surface *screen,SDL_Surface *imgfond ,int running,SDL_Rect posfond)
     {
    posfond.x = 0;
    posfond.y = 0;
    posfond.h =500;
    posfond.w =1920;

    
    imgfond = IMG_Load("backg.png");
   
  SDL_BlitSurface(imgfond,&posfond,screen, NULL);
              
    SDL_Flip(screen);
    
 
    SDL_Event event;
    SDL_EnableKeyRepeat(10, 10);
 
    while (running)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                running= 0;
                break;
            case SDL_KEYDOWN:

        switch(event.key.keysym.sym)

        {

            case SDLK_RIGHT: // appui sure la flèche droite
            	
                if  ( posfond.x<=5760)
       
            posfond.x += 10;
     
            
       
                SDL_BlitSurface(imgfond,&posfond,screen, NULL);
            
                
    SDL_Flip(screen);

                break;

            case SDLK_LEFT: // appui sur la flèche gauche
            	if ( posfond.x>=0)
        
            posfond.x -= 10;
     
         
                SDL_BlitSurface(imgfond,&posfond,screen, NULL);
				
                
    SDL_Flip(screen);

                break;
              

        }

        break;    
        }

       
        
    SDL_Flip(screen);
    }
}
