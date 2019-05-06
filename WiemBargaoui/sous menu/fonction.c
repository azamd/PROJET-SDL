#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "SDL/SDL_gfxPrimitives.h"
#include "SDL/SDL_mixer.h"
#include "fonction.h"



void setup (Objet *sous_menukey,Objet *sous_menumouse ,Objet *volume100,Objet *volume75,Objet *volume50,Objet *volume25,Objet *volume0,Objet *sous_menucontroller)
{
  
  sous_menucontroller->img=IMG_Load("Menu_joystick.png") ;
  sous_menucontroller->pos.x=0 ;
  sous_menucontroller->pos.y=0 ;

  sous_menukey->img=IMG_Load("Menu_keyboard.png") ;
  sous_menukey->pos.x=0 ;
  sous_menukey->pos.y=0 ;

  sous_menumouse->img=IMG_Load("Menu_mouse.png") ;
  sous_menumouse->pos.x=0 ;
  sous_menumouse->pos.y=0 ;

  volume100->img=IMG_Load("volume100.png") ;
  volume100->pos.x=0 ;
  volume100->pos.y=0 ;

  volume75->img=IMG_Load("volume75.png") ;
  volume75->pos.x=0 ;
  volume75->pos.y=0 ;

  volume50->img=IMG_Load("volume50.png") ;
  volume50->pos.x=0 ;
  volume50->pos.y=0 ;

  volume25->img=IMG_Load("volume25.png") ;
  volume25->pos.x=0 ;
  volume25->pos.y=0 ;

  volume0->img=IMG_Load("volume0.png") ;
  volume0->pos.x=0 ;
  volume0->pos.y=0 ;
  
  

}