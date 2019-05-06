/**
* @file menuingame.c
*/

#include "fonction.h"
/**
* @brief To control volume of the music of the game  .
* @param continuer0
* @param ecran
* @return Nothing
*/
void volumme(int *continuer0,SDL_Surface *ecran)
{
int n=1,volume=128;
int continuer1=1;
SDL_Rect pos;
SDL_Event event;
SDL_Surface *bouts=NULL,*bout=NULL;
pos.x=0;
pos.y=0;

bout=IMG_Load("../assets/menu/bout.png") ;
bouts=IMG_Load("../assets/menu/bouts.png") ;
while (continuer1)
{
SDL_PollEvent(&event);
switch(event.type)
    {
	case SDL_KEYDOWN:

	    switch (event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
    		continuer1=0 ;
		*continuer0=0 ;
    			break ;
		case SDLK_KP_PLUS :
		    volume = volume + 4 ;
			break ;
		case SDLK_KP_MINUS :
		    volume = volume - 4 ;
			break ;
		case SDLK_p :
		    switch(n)
			{
			case 1:
			Mix_PauseMusic();
			n=2;
				break ;
			case 2:
			Mix_ResumeMusic();
			n=1 ;
				break ;
			}
		}
		break ;
	}
Mix_VolumeMusic(volume);
SDL_BlitSurface(bout, NULL, ecran, &pos);
SDL_Flip(ecran);
}	
}
/**
* @brief To set the  second menu in the game .
* @param continuer
* @param ennemi
* @param perso
* @param page1
* @param page2
* @param vie
* @param saut
* @param camera
* @param ecran
* @return Nothing
*/

void menuingame(int *continuer,ennemis ennemi,perso perso,int page1,int page2,vie vie,int saut,SDL_Rect camera,SDL_Surface *ecran)
{
int n=1,continuer0=1,continuer1=1;
SDL_Surface *bout=NULL,*bouts=NULL;
SDL_Rect pos;
SDL_Event event;

pos.x=0;
pos.y=0;
bouts=IMG_Load("../assets/menu/bouts.png") ;
bout=IMG_Load("../assets/menu/bout.png") ;

continuer0 = 1 ;
while (continuer0)
{
SDL_PollEvent(&event);
switch(event.type)
    {
	case SDL_QUIT:
	    continuer0 = 0;
	    *continuer = 0 ;
  		break;

	case SDL_KEYDOWN:

	    switch (event.key.keysym.sym)
	    {
		case SDLK_ESCAPE:
		    continuer0=0 ;
		    	break ;
		case SDLK_KP1 :
		savee(ennemi,perso,page1,page2,vie,saut,camera);
		continuer0=0;	
			break ;

		case SDLK_KP2 :
		volumme(&continuer0,ecran);
			break;
	 
		case SDLK_KP3:
			if(n==1)
			{
			ecran = SDL_SetVideoMode(1000, 560, 32, SDL_HWSURFACE | SDL_DOUBLEBUF |SDL_FULLSCREEN );
			n=2;
			}
			if(n==2)
			{
			ecran = SDL_SetVideoMode(1000, 560, 32, SDL_HWSURFACE | SDL_DOUBLEBUF );
			n=1;
			}
			continuer0 = 0;
			break;

		case SDLK_KP4:
		continuer1=1;
		while (continuer1)
		{
		SDL_PollEvent(&event);
		switch(event.type)
		    {
			case SDL_KEYDOWN:

			    switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
		    		continuer1=0 ;
				break;
				case SDLK_KP1:
				continuer1 = 0;
				continuer0 = 0;
				*continuer = 0 ;
				break;
				case SDLK_KP2:
				savee(ennemi,perso,page1,page2,vie,saut,camera);
				continuer1 = 0;
				continuer0 = 0;
				*continuer = 0 ;
				break;
				}

			}
		SDL_BlitSurface(bouts, NULL, ecran, &pos);
		SDL_Flip(ecran);
		}
			break;
	}   
    }
SDL_BlitSurface(bout, NULL, ecran, &pos);
SDL_Flip(ecran);
}
}



