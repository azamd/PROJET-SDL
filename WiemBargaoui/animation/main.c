#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "SDL/SDL_gfxPrimitives.h"
#include "SDL/SDL_mixer.h"
#include "animation.h"


int main ()
{
  SDL_Surface *screen=NULL ;
  SDL_Init(SDL_INIT_VIDEO) ;

  
  screen=SDL_SetVideoMode(1366,768,32,SDL_HWSURFACE | SDL_DOUBLEBUF ) ;
  Objet tab [200],tab2[200] ;
  SDL_Event event ;
  int running=1,i=0,actuel=0,prec=0,j=0 ; 
  load_transition1(tab) ;
  load_transition(tab2) ;
    while(running){
                 
                  if (i<=179)   
                   { 
                     actuel = SDL_GetTicks();
                      if (actuel - prec > 50)
                         {
                           update_transition(screen ,tab,&i) ;
                           prec = actuel;

                         }
                      else 
                         {
                           SDL_Delay(50 - (actuel - prec));
                         }
                   }
                  if(i>179) 
                  {
                  if (j<=189)   
                   { 
                     actuel = SDL_GetTicks();
                      if (actuel - prec > 50)
                         {
                           update_transition(screen ,tab2,&j) ;
                           prec = actuel;

                         }
                      else 
                         {
                           SDL_Delay(50 - (actuel - prec));
                         }
                   }
                  }
                    SDL_PollEvent(&event) ;
                        switch(event.type)
               {
                case SDL_QUIT:
                running = 0 ;
                break;
               }
                

    }
  SDL_Quit();
}