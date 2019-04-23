#ifndef JEUX_H_
#define JEUX_H_
#include "fonction.h"
typedef struct saves
{
perso perso;
SDL_Rect camera;
ennemis ennemi;
vie vie;
int page1,page2,saut,level;
}saves;

void savee(ennemis ennemi,perso perso,int page1,int page2,vie vie,int saut,SDL_Rect camera);
void load(int lvl,ennemis *ennemi,perso *perso,int page1,int page2,vie *vie,int *saut,SDL_Rect *camera,int *continuer,int *save);
void level1(int *save,int lvl);
#endif 

