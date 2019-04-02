#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

int initobjet 
{
	SDL_Surface *objet;
	
	SDL_Surface *screen;
	SDL_Event event;
	SDL_Rect positionobjet,positionscreen;


	int objet_x = 20;
	int objet_y = 5;
	



	if(SDL_Init(SDL_INIT_VIDEO)!=0)
	{
		printf("Unable to initialize SDL:%s\n",SDL_GetError());
		return 1;
	}
	screen=SDL_SetVideoMode(660,260,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	if(screen==NULL)
	{
		printf("unable to set video mode :%s\n",SDL_GetError());
		return 1;
	}
	
	


	objet=IMG_Load("objet.png");	
	if(image==NULL)
	{
		printf("unable to load bitamp: %s",SDL_GetError());
		return 1;
	}
	
	

	

	positionobjet1.x = ecran_x;
	positionobjet1.y = ecran_y;
	


	SDL_BlitSurface(image, NULL, screen, &positionscreen);
	
	SDL_BlitSurface(objet, NULL, screen, &positionobjet);

	
	
	

}
