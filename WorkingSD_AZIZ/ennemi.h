#ifndef ENNEMI_H_
#define ENNEMI_H_
typedef struct ennemis
{
	SDL_Rect position;
	SDL_Rect position2;
	SDL_Surface *fond;
	SDL_Surface *fond1;
	SDL_Surface *fond2;
	SDL_Surface *fonda;
	SDL_Surface *fondb;
}ennemis;

void initialiserennemi(ennemis *ennemi);
void freesurfaceennemi(ennemis *ennemi);
ennemis mouvennemi(ennemis ennemi,perso perso,int d,int q,SDL_Rect camera,SDL_Surface *ecran,int *ennmouv,int *w,int *y,int mvmspeed);
int splitennemi(int y);
void afficherennemi(ennemis ennemi,SDL_Surface *ecran,int y);
#endif 
