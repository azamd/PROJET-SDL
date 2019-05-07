#ifndef HEADERNAME_H_INCLUDED
#define HEADERNAME_H_INCLUDED

typedef struct 
{ 
  SDL_Surface* srf;
  SDL_Rect pos;
}Imm; 
typedef struct person
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
}person;

void initmm(person *perso,Imm* ecran,Imm* curseur,Imm* mini_map);
void loadmm(Imm* curseur,Imm* mini_map);
void display(Imm* ecran ,Imm* curseur,Imm* mini_map );
void mini_map(Imm * curseur ,person *perso);
#endif
