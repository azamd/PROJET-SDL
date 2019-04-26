/**  
* @file enigf.c
* @author Yassine Kochat :you should resolve the enigme by putting the right response with this buttons : q:solution 1 ,s;solution=2 ,d:solution=3
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "enig.h"


void init_enigme(enigme * e)
{
/** 
	
* @brief  To initialize the enigf b . 
	* @param enigme *e the enigf 
	* @param url  the url of the image  
	* @return Nothing 
 */ 
	e->p.x=0;
	e->p.y=0;	
	e->img=NULL;


}


 void generate_afficher (SDL_Surface * screen  , char image [],enigme *e,int *alea)
{ 
 /**   
 * @brief  To show the enigf b . 
 * @param scren the screen 
 * @param image  the enigf 
 * @param alea   the enigf
 * @param enigme *e  the enigf  
 * @return Nothing  
*/
	int test=*alea ;
do{
 *alea = 1+ rand()%3;
}while(*alea==test) ;
 sprintf(image ,"%d.jpg",*alea);
e->img = IMG_Load(image);
 SDL_BlitSurface(e->img,NULL,screen,&(e->p)) ;
  SDL_Flip(screen) ;
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
 		solution =1;

 	}
 	else 	if(strcmp(image,"3.jpg")==0)
 	{
 		solution =1;	
 	}
 	return solution;
 }
/**  * @brief  To give the solution of the enigf . 
 * @param image  the enigf
 * @return solution 
s */

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
			  case  SDLK_q: 
			  r= 1;
			   break ;
			   case  SDLK_s :
			   r=2;
			   break;
			   case SDLK_d: 
			   r=3;
			   break;
			    }
       break ;

                 
	}
  return r ;
}
/**  * @brief  To show the solution of the enigf . 
 * @param scren the screen 
 * @param s,r and enigmes *en  the enigf 
 * @return Nothing  
*/
 
 void afficher_resultat (SDL_Surface * screen,int s,int r,enigme *en)
 {
 
 	if (r==s)
 	{
 		en->img=IMG_Load("11.jpg");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
 	}
 	else
 	{
 		en->img=IMG_Load("11.jpg");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
 	}
 }
 
