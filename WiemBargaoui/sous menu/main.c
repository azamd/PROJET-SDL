#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "SDL/SDL_gfxPrimitives.h"
#include "SDL/SDL_mixer.h"
#include "fonction.h"



int main ()
{

 int running=1,i=0,j=4,keyboard=0,mouse=1,controller=0,k=3 ;
 SDL_Surface *screen=NULL ;
 Objet volume0 ,volume25,volume50,volume75,volume100,sous_menumouse,sous_menukey,sous_menucontroller ;
SDL_Event event ;
SDL_Init (SDL_INIT_EVERYTHING) ;
 screen=SDL_SetVideoMode(900,425,32,SDL_HWSURFACE | SDL_DOUBLEBUF) ;
setup (&sous_menukey,&sous_menumouse ,&volume100,&volume75,&volume50,&volume25,&volume0,&sous_menucontroller) ;
SDL_EnableKeyRepeat(100,100) ;
while(running){
                  SDL_WaitEvent(&event) ;
                        switch(event.type)
               {
                case SDL_QUIT:
                running = 0 ;
                break;
                case SDL_KEYDOWN :
                switch(event.key.keysym.sym)
                {
                 case SDLK_ESCAPE:
                    running=0 ;
                  break ;
                 case SDLK_RIGHT :
                  if(i==1)
                  {
                    j++ ;
                    if(j>4)
                    j=4 ;
                  }
                  else if (i==0)
                  {
                   k++ ;
                   if(k>3)
                    k=1 ;
                  }
                 break ;
                 case SDLK_LEFT :
                 if(i)
                 {
                    j-- ;
                    if(j<0)
                    j=0 ;   
                 } 
                  else if (i==0)
                  {
                    k -- ;
                   if(k<1)
                    k=3 ;
                  }             
                 break ;

                 case SDLK_UP :
                   i--  ;
                   if(i<0)
                   i=1 ;
                 break ;
                 case SDLK_DOWN :
                   i ++ ;
                   if(i>1)
                   i=0 ;
                  break ;
         
                }
                break ;
               }
  if(i==0)
  {
    if(k==2)
    SDL_BlitSurface(sous_menukey.img,NULL,screen,&(sous_menukey.pos)) ;
    else if (k==1)
    SDL_BlitSurface(sous_menumouse.img,NULL,screen,&(sous_menumouse.pos)) ;  
    else if (k==3) 
    SDL_BlitSurface(sous_menucontroller.img,NULL,screen,&(sous_menucontroller.pos)) ;  

  }
  else if(i)
  {

    if (j==4)
   SDL_BlitSurface(volume100.img,NULL,screen,&(volume100.pos)) ;  
   else if (j==3)
   SDL_BlitSurface(volume75.img,NULL,screen,&(volume75.pos)) ;  
   else if (j==2) 
   SDL_BlitSurface(volume50.img,NULL,screen,&(volume50.pos)) ;  
    else if(j==1)
   SDL_BlitSurface(volume25.img,NULL,screen,&(volume25.pos)) ;  
    else if (j==0)
   SDL_BlitSurface(volume0.img,NULL,screen,&(volume0.pos)) ;  

  }
  
  SDL_Flip(screen) ;
}


SDL_Quit () ;
}