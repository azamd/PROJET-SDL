#ifndef JEUX_H_
#define JEUX_H_
#include "fonction.h"
/**
* @struct saves
* @brief struct for saves
* @author CyberPunkTeam
* @version 0.2 Alpha Build
* @date Apr 23, 2019
*/
typedef struct saves
{
perso perso; /*!< Character Struct*/
SDL_Rect camera;	/*!< Camera's Rectangle*/
ennemis ennemi;		/*!< Ennemy Struct*/
vie vie;		/*!< Life Points Struct*/
int page1,page2,saut,level;
}saves;

void savee(ennemis ennemi,perso perso,int page1,int page2,vie vie,int saut,SDL_Rect camera);
void load(int lvl,ennemis *ennemi,perso *perso,int page1,int page2,vie *vie,int *saut,SDL_Rect *camera,int *continuer,int *save);
void level1(int *save,int lvl);
#endif 

