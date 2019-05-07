#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "SDL/SDL_gfxPrimitives.h"
#include "SDL/SDL_mixer.h"
#include "animation.h"




void load_transition(Objett tab [] )
{
  int i ;
  char image [50] ;
  for(i=0;i<189;i++)
  {
        if(i<9)
    sprintf(image,"../assets/menu/intro/%d.png",i+1) ;
    else if (i<99 && i>=9)
    sprintf(image,"../assets/menu/intro/%d.png",i+1) ;
    else if (i>=99)
    sprintf(image,"../assets/menu/intro/%d.png",i+1) ;
    
    
    tab[i].img=IMG_Load(image) ;
    tab[i].pos.x=0 ;
    tab[i].pos.y=0 ;
  }
}
void load_transition1(Objett tab [] )
{
  int i ;
  char image [50] ;
  for(i=0;i<179;i++)
  {
    sprintf(image,"../assets/menu/intro/%d.png",i+1) ;
    
    tab[i].img=IMG_Load(image) ;
    tab[i].pos.x=0 ;
    tab[i].pos.y=0 ;
  }
}
void update_transition(SDL_Surface *screen ,Objett tab [],int *i)
{
    
    update(screen,&tab[*i],NULL) ;

    if((*i)>=1)
    SDL_FreeSurface((tab[(*i)-1].img));
    (*i)++ ;
  
}
void update (SDL_Surface *screen , Objett *surface1,Objett *surface2)
{
  if(surface1!=NULL)
  SDL_BlitSurface(surface1->img, NULL, screen, &(surface1->pos));
  if(surface2!=NULL)
  SDL_BlitSurface(surface2->img, NULL, screen, &(surface2->pos));

  SDL_Flip (screen) ;
}
