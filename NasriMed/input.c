#include<SDL/SDL.h>
#include"struct.h"

void getInput(Input* input){
	SDL_Event event;
	SDL_PollEvent(&event);
	switch(event.type){
		//clavier 
		case SDL_KEYDOWN :
			switch (event.key.keysym.sym)
			{
				case SDLK_UP : 
					input->haut = 1;
					//printf("%d", input->haut);
				break;
		
				case SDLK_DOWN :                                    
					input->bas = 1;
				break;

				case SDLK_RIGHT : 
					input->droite = 1;
				break;
		
				case SDLK_LEFT : 
					input->gauche = 1;	
				break;

				case SDLK_ESCAPE:
					exit(1);
				break;
			}	
		break;

	case SDL_KEYUP :
			switch (event.key.keysym.sym)
			{
				case SDLK_UP : 
					input->haut = 0;
				break;
		
				case SDLK_DOWN :                                    
					input->bas = 0;
				break;

				case SDLK_RIGHT : 
					input->droite = 0;
				break;
		
				case SDLK_LEFT : 
					input->gauche = 0;	
				break;

				case SDLK_ESCAPE:
					exit(1);
				break;
			}	

	}
}