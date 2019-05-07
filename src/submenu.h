#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


typedef struct 
{

  SDL_Surface *img ;
  SDL_Rect pos ;
  SDL_Rect pos_text ;

  
}Objet ;


void setup (Objet *sous_menukey,Objet *sous_menumouse ,Objet *volume100,Objet *volume75,Objet *volume50,Objet *volume25,Objet *volume0,Objet *sous_menucontroller) ;
