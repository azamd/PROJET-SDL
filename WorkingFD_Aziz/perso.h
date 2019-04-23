#ifndef PERSO_H_
#define PERSO_H_

typedef struct perso
{
	int a;
	SDL_Rect position;
	SDL_Surface *fond00;
	SDL_Surface *fond0;
	SDL_Surface *fond1;
	SDL_Surface *fond2;
	SDL_Surface *fond3;
	SDL_Surface *fonda;
	SDL_Surface *fondb;
	SDL_Surface *fondc;
}perso;

typedef struct vie
{
	int nb;
	SDL_Rect position;
	SDL_Rect position2;
	SDL_Surface *fond1;
	SDL_Surface *fond2;
	SDL_Surface *fond3;
	SDL_Surface *fond4;
	SDL_Surface *fond5;
}vie;


void initialiserperso(perso *perso);
void initialiserperso2(perso *perso);
void initialiserperso3(perso *perso);
void freefurfaceperso(perso *perso);
int mouv(int d,int q,int z,int s,int x,perso perso,escalier escalier,SDL_Rect camera);
void splitperso2(int d,int q,int *x);
void mouvperso2(int d,int q,perso *perso,int jump,int *saut,SDL_Rect camera,map map,int prevd,int prevq,int *continuer,SDL_Surface *ecran,int *save);
void mouvperso3(int d,int q,perso *perso,int jump,int *saut,SDL_Rect camera,map map,int prevd,int prevq,int *continuer,SDL_Surface *ecran);
void obstacle2(vie *vie,map map,perso *perso,SDL_Rect *camera);
void obstacle(vie *vie,map map,perso *perso,SDL_Rect *camera);
perso mouvement(perso perso,SDL_Rect camera,int h,int d,int q,int z,int s,escalier escalier,int prevd,int prevq,int *saut,int jump,int speed);
void afficherperso(perso perso,SDL_Surface *ecran,int x);

void initialiservie(vie *vie);
void freesurfacevie(vie *vie);
void affichervie(vie *vie,perso perso,SDL_Surface *ecran);

#endif 
