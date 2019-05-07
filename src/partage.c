#include "partage.h"


void afficher_background(backgr *bg)
{
bg->pos.x=0;
bg->pos.y=0;
image=IMG_Load("back3.png");
SDL_BlitSurface(image,NULL,ecran,&bg->pos);
}

void afficher_background1(backgr *bg1)
{
bg1->pos.x=0;
bg1->pos.y=261;
image=IMG_Load("back3.png");
SDL_BlitSurface(image,NULL,ecran,&bg1->pos);
}
void afficher_perso(perso *p)
{

image=IMG_Load("perso.png");
SDL_BlitSurface(image,NULL,ecran,&p->posper);
//SDL_Flip(ecran);
}

void afficher_perso1(perso *p1)
{
image=IMG_Load("perso1.png");
SDL_BlitSurface(image,NULL,ecran,&p1->posper);
//SDL_Flip(ecran);
}

int main(int argc, char *argv[])
{
int run =1;
SDL_Init(SDL_INIT_EVERYTHING);
ecran=SDL_SetVideoMode(900,522,32,SDL_HWSURFACE|SDL_RESIZABLE);
backgr bg;
backgr bg1;
perso p;
perso p1;
SDL_Event event;
SDL_EnableKeyRepeat(10,10);
p.posper.x=10;
p.posper.y=70;
p1.posper.x=10;
p1.posper.y=320;
while(run)
{
while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT)
					run = 0;
			if(event.type == SDL_KEYDOWN) {
				if(event.key.keysym.sym == SDLK_ESCAPE)
						run = 0;
				if(event.key.keysym.sym == SDLK_RIGHT) {
					p.posper.x += 5;
				}
				if(event.key.keysym.sym == SDLK_LEFT) {
					p.posper.x -= 5;
				}
				if(event.key.keysym.sym == SDLK_d) {
					p1.posper.x += 5;
				}
				if(event.key.keysym.sym == SDLK_s) {
					p1.posper.x -= 5;
				}
			}
		}

afficher_background(&bg);
afficher_background1(&bg1);
afficher_perso(&p);
afficher_perso1(&p1);
SDL_Flip(ecran);
}
    SDL_Quit();

    return EXIT_SUCCESS;

}
