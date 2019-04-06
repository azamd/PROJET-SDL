#include"struct.h"

int main(){
	int i=3;
	SDL_Surface *screen=NULL;
	Perso p, p1;
	vie v;
	Input input;
	Background back;

	SDL_Init(SDL_INIT_VIDEO);
	screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);

	init_perso(&p);
	init_perso(&p1);
	vie_init(&v);
	p1.pos.x=500;
	init_background(&back, "back.jpg", "back.jpg");

	while(1){

		afficher_background(&back, screen);
		afficher(&p, screen);
		afficher(&p1, screen);
		vie_display(&v,&p,screen);
		SDL_Flip(screen);
		getInput(&input);
		if(input.droite==1)
		{
			if(check_collision(&p, &p1, 1)==0)
				deplacer(&p, 1);
			else v.nb--;
		}
		else if(input.gauche==1){
			if(check_collision(&p, &p1, 2)==0)
				deplacer(&p, 2);
		}
		else if(input.haut==1){
			if(check_collision(&p, &p1, 3)==0)
				deplacer(&p, 3);
		}
		else if(input.bas==1){
			if(check_collision(&p, &p1, 4)==0)
				deplacer(&p, 4);
		}
		


}
	vie_free(&v);
	return 0;
}
