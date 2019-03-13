#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include"struct.h"

void init_perso(Perso *p){
	p->tab[0]=IMG_Load("Run1.png");
	p->tab[1]=IMG_Load("Run2.png");
	p->tab[2]=IMG_Load("Run3.png");

	p->pos.x=20;
	p->pos.y=30;
	p->pos.w= p->tab[0]->w;
	p->pos.h= p->tab[0]->h;
	
	p->frame=0;
}


void afficher(Perso *p, SDL_Surface *screen){
	//SDL_Delay(25);
	SDL_BlitSurface(p->tab[p->frame], NULL, screen, &p->pos);	
}

void animer(Perso *p){
	if(p->frame==2)
		p->frame=0;
	else
		p->frame++;
}

void deplacer(Perso *p, int direction){
	switch(direction){
		case 1:
			p->pos.x+=2;
		break;

		case 2:
			p->pos.x-=2;
		break;


		case 3:
			p->pos.y-=2;
		break;


		case 4:
			p->pos.y+=2;
		break;
	}

	animer(p);
}