#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scroll.h"

void scrolling(SDL_Surface *screen,SDL_Surface *imgfond ,int running,SDL_Rect posfond)
     {
    posfond.x = 0;   //définition des coordonnés (sure l'axe x,y)
    posfond.y = 0;
    posfond.h =500;  //Hauteur h
    posfond.w =1920  //Largeur w

    
    imgfond = IMG_Load("backg.png");  //chargement de l'image du fond (background)
   
  SDL_BlitSurface(imgfond,&posfond,screen, NULL);  //ajuster l'image du fond dans la position predefinie
              
    SDL_Flip(screen); //mise a jour
    
 
    SDL_Event event;
    SDL_EnableKeyRepeat(10, 10);
 
    while (running) // running==1
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT: //appui sur le bouton de fermeture (x)
                running= 0;
                break;
            case SDL_KEYDOWN:

        switch(event.key.keysym.sym)

        {

            case SDLK_RIGHT: // appui sure la flèche droite
            	
                if  ( posfond.x<=5760)
       
            posfond.x += 10; // translation vers gauche du background sur l'axe x 
     
            
       
                SDL_BlitSurface(imgfond,&posfond,screen, NULL);
            
                
    SDL_Flip(screen);

                break;

            case SDLK_LEFT: // appui sur la flèche gauche
            	if ( posfond.x>=0)
        
            posfond.x -= 10; // translation vers droite du background sur l'axe x
     
         
                SDL_BlitSurface(imgfond,&posfond,screen, NULL);
				
                
    SDL_Flip(screen);

                break;  }
		break;  }
   
    SDL_Flip(screen);
    }
}
