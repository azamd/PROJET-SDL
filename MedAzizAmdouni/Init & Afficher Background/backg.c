#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "heads.h"


 SDL_Surface * Init_Background(SDL_Surface *backg, SDL_Rect *backg_rect ,int x,int y)
{

  backg= IMG_Load("backg.png");

if  ( backg ==  NULL ) 
 { 
         printf ( "Error, It's impossible to load the chosen image !: %s \n " , SDL_GetError ()); 
         exit ( 1 ); 
     } 
    else 
     {
 
     backg_rect->x = x ; 
     backg_rect->y = y ;
     backg_rect->h= backg->h ;
     backg_rect->w= backg->w ;  
 }
     
     return (backg) ; 
}
 void Afficher_Background(SDL_Surface *backg , SDL_Surface *screen , SDL_Rect backg_rect ) 
  {

	 SDL_BlitSurface(backg, NULL, screen, &backg_rect);
}
















