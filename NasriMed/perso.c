#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include"struct.h"
void vie_init(vie *vie)
{
vie->nb=3;
vie->position.x = 0 ;
vie->position.y = 0 ;
vie->position2.x = 0 ;
vie->position2.y = 0 ;
vie->heart1 = IMG_Load("v1.png");
vie->heart2 = IMG_Load("v2.png");
vie->heart3 = IMG_Load("v3.png");
vie->heart4 = IMG_Load("v4.png");
vie->gameover = IMG_Load("GameOver.png");
}

void vie_free(vie *vie)
{
SDL_FreeSurface(vie->heart1);
SDL_FreeSurface(vie->heart2);
SDL_FreeSurface(vie->heart3);
SDL_FreeSurface(vie->heart4);
SDL_FreeSurface(vie->gameover);
}
//void vie_display(vie *vie,Perso *p,SDL_Surface *screen, int nb)
void vie_display(vie *vie,Perso *p,SDL_Surface *screen)
{
vie->position.x=p->pos.x-30;
vie->position.y=p->pos.y-40;
if(vie->nb==3)
{
SDL_BlitSurface(vie->heart1,NULL, screen,&vie->position);

}
if(vie->nb==2)
{
SDL_BlitSurface(vie->heart2,NULL, screen,&vie->position);
}
if(vie->nb==1)
{
SDL_BlitSurface(vie->heart3,NULL, screen,&vie->position);
}
if(vie->nb==0)
{
SDL_BlitSurface(vie->heart4,NULL, screen,&vie->position);
SDL_BlitSurface(vie->gameover,NULL, screen,&vie->position2);
vie->nb=3;
SDL_Flip(screen);
sleep(4);
}
}


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
