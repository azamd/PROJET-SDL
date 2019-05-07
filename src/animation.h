#include <SDL/SDL.h>
#include <SDL/SDL_image.h>




typedef struct 
{

  SDL_Surface *img ;
  SDL_Rect pos ;
  SDL_Rect pos_text ;

  
}Objett ;
void load_transition(Objett tab [] ) ;
void load_transition1(Objett tab [] ) ;
void update_transition(SDL_Surface *screen ,Objett tab [],int *i) ;
void update (SDL_Surface *screen , Objett *surface1,Objett *surface2) ;
