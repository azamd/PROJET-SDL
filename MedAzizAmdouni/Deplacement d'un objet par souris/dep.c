#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include "dep.h"

void translation(SDL_Surface *screen,SDL_Surface *img ,int running,SDL_Rect pos)
{


    SDL_Event event;

        SDL_WaitEvent(&event);
         
        switch(event.type)
        {
 case SDL_QUIT :
         running = 0;
         break;

         case SDL_MOUSEBUTTONUP:
             if(event.button.button==SDL_BUTTON_LEFT)
              {
              pos.x = event.button.x-513;
             pos.y = event.button.y-400;

      SDL_BlitSurface(img,NULL,screen,&pos);
              }
              else if (event.button.button==SDL_BUTTON_RIGHT)

              running=0;

              break ;
         case SDL_ACTIVEEVENT :
                   if ((event.active.state & SDL_APPMOUSEFOCUS) == SDL_APPMOUSEFOCUS)
{
      if (event.active.gain == 0)  
        {
         pos.x ++ ;
         pos.y++ ;
SDL_BlitSurface(img,NULL,screen,&pos);
        }
      else if (event.active.gain == 1)  
        {
                   pos.x ++ ;
                   pos.y ++ ;
SDL_BlitSurface(img,NULL,screen,&pos);

            break ;
        }

}

SDL_BlitSurface(img,NULL,screen,&pos);
}

}
