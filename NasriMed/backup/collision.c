#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include"struct.h"


void init_background (Background *background, char* pathImg, char *pathMask)
{
	
	background->img = IMG_Load (pathImg);
 	background->mask = IMG_Load (pathMask);
	background->pos.x=0;
	background->pos.y=0;
	background->camera.x=0;
	background->camera.y=0;
	background->camera.w=800;
	background->camera.h=600;
}


//afficher background
void afficher_background (Background *background, SDL_Surface *ecran)
{
	SDL_BlitSurface (background->img, &background->camera, ecran, &background->pos); // blit du background
}


// collision entre deux entité
int check_collision (Perso *personnage1, Perso *personnage2, int direction)
{	
	//printf("x : %d  x1: %d  w: %d\n", personnage1->pos.x, personnage2->pos.x, personnage1->pos.w);
	if(direction==2){
		if((personnage1->pos.x >= personnage2->pos.x + personnage2->pos.w))
			return 1;
		else return 0;	
	}


	if(direction==1){
		if((personnage1->pos.x + personnage1->pos.w >= personnage2->pos.x))
			return 1;
		else return 0;	
	}

	if(direction==4){
		if((personnage1->pos.y + personnage1->pos.h <= personnage2->pos.y))
			return 1;
		else return 0;	
	}
	if(direction==3){
		if((personnage1->pos.y <= personnage2->pos.y + personnage2->pos.h))
			return 1;
		else return 0;	
	}
/*
	if((personnage1->pos.x >= personnage2->pos.x + personnage2->pos.w)      // trop à droite
	|| (personnage1->pos.x + personnage1->pos.w <= personnage2->pos.x) // trop à gauche
        || (personnage1->pos.y >= personnage2->pos.y + personnage2->pos.h) // trop en bas
	|| (personnage1->pos.y + personnage1->pos.h <= personnage2->pos.y))  // trop en haut
			return 1;
	return 0;*/
 
}