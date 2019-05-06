#include <SDL/SDL.h>
#include <SDL/SDL_image.h>




typedef struct 
{

  SDL_Surface *img ;
  SDL_Rect pos ;
  SDL_Rect pos_text ;

  
}Objet ;
void load_transition(Objet tab [] ) ;
void load_transition1(Objet tab [] ) ;
void update_transition(SDL_Surface *screen ,Objet tab [],int *i) ;
void update (SDL_Surface *screen , Objet *surface1,Objet *surface2) ;
