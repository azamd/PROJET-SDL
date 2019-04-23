#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "enigme.h"

void init_enigme(enigme * enig)
{
	enig->p.x=0;
	enig->p.y=0;	
	enig->img=NULL;


}

 void generate_afficher (SDL_Surface * ecran  , char image [],enigme *enig,int *alea)
{ 
	int test=*alea ;
do{
 *alea = 1+ rand()%3;
}while(*alea==test) ;
 sprintf(image ,"%d.jpg",*alea);
enig->img = IMG_Load(image);
 SDL_BlitSurface(enig->img,NULL,ecran,&(enig->p)) ;
  SDL_Flip(ecran) ;
}
 
 int solution_e (char image [])
 {
 	int solution =0 ;
 	
 	if(strcmp(image,"1.jpg")==0)
 	{
     solution =1 ;
 	}
 	else  	if(strcmp(image,"2.jpg")==0)
 	{
 		solution =2;

 	}
 	else 	if(strcmp(image,"3.jpg")==0)
 	{
 		solution =1;	
 	}
 	return solution;
 }

int resolution (int * running,int *run )
{
	SDL_Event event ;
  int r=0 ;
	SDL_PollEvent(&event);
	switch(event.type)
	{
		  case SDL_QUIT:
			        *running= 0 ;
                *run = 0;
				break ;

       case SDL_KEYDOWN : 
            switch( event.key.keysym.sym )
                {
                           case SDLK_ESCAPE :
                              *run=0 ;
                           break ;
			  case  SDLK_a: 
			   r= 1;
			   break ;
			   case  SDLK_z :
			   r= 2;
			   break;
			   case SDLK_e: 
			   r=3 ;
			   break;
			    }
       break ;

                 
	}
  return r ;
}
 
 void afficher_resultat (SDL_Surface * ecran,int sol,int r,enigme *en)
 {
 
 	if (r==sol)
 	{
 		en->img=IMG_Load("00.jpg");
 		SDL_BlitSurface(en->img, NULL, ecran, &(en->p)) ;
        SDL_Flip(ecran);
 	}
 	else
 	{
 		en->img=IMG_Load("00.jpg");
 		SDL_BlitSurface(en->img, NULL, ecran, &(en->p)) ;
        SDL_Flip(ecran);
 	}
 }
 
