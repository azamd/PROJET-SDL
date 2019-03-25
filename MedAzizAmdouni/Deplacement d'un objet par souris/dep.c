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

         case SDL_MOUSEBUTTONUP: // cliquer la souris
             if(event.button.button==SDL_BUTTON_LEFT) // bouton gauche de la souris
              {
              pos.x = event.button.x-513;
             pos.y = event.button.y-400;

      SDL_BlitSurface(img,NULL,screen,&pos);
              }
              else if (event.button.button==SDL_BUTTON_RIGHT) // bouton droit de la souris

              running=0;

              break ;
         case SDL_ACTIVEEVENT : //gérer la fenetre
                   if ((event.active.state & SDL_APPMOUSEFOCUS) == SDL_APPMOUSEFOCUS) //verification de l'etat de la souris
{
      if (event.active.gain == 0)  // cas n°1 : le curseur hors la fenetre.
        {
         pos.x ++ ;
         pos.y ++ ;
         SDL_BlitSurface(img,NULL,screen,&pos);
        }
      else if (event.active.gain == 1) // cas n°2 : le curseur dans la fenetre. 
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
