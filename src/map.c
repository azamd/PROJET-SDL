/**
* @file map.c
*/
#include "fonction.h"
/**
* @brief To initialize the background map .
* @param map the background
* @return Nothing
*/

void initialiserfond(map *map)
{
map->position.x = 0 ;
map->position.y = 0 ;
map->fond = IMG_Load("../assets/map/map.png");
map->fond2 = IMG_Load("../assets/map/map2.png");
}
/**
* @brief To initialize the background map .
* @param map the background
* @return Nothing
*/
void initialiserfond2(map *map)
{
map->position.x = 0 ;
map->position.y = 0 ;
map->fond = IMG_Load("../assets/map/map2.jpg");
map->fond2 = IMG_Load("../assets/map/mapp2.png");
map->fond3 = IMG_Load("../assets/map/mappp2.png");
map->ff1 = IMG_Load("../assets/map/ff1.png");
map->ff2 = IMG_Load("../assets/map/ff2.png");
map->ff3 = IMG_Load("../assets/map/ff3.png");
map->ff4 = IMG_Load("../assets/map/ff4.png");
map->ff5 = IMG_Load("../assets/map/ff5.png");
map->ff6 = IMG_Load("../assets/map/ff6.png");
map->ff7 = IMG_Load("../assets/map/ff7.png");
map->ff8 = IMG_Load("../assets/map/ff8.png");
map->ff9 = IMG_Load("../assets/map/ff9.png");
map->ff10 = IMG_Load("../assets/map/black.png");
}

/**
* @brief To initialize the background map .
* @param map the background
* @return Nothing
*/
void initialiserfond3(map *map)
{
map->position.x = 0 ;
map->position.y = 0 ;
map->fond = IMG_Load("../assets/map/map3.png");
map->fond2 = IMG_Load("../assets/map/mapp3.png");
}

/**
* @brief To initialize escalier .
* @param escalier : escalier
* @return Nothing
*/
void initialiserescalier(escalier *escalier)
{
escalier->position.x = 0 ;
escalier->position.y = 0 ;
escalier->fond = IMG_Load("../assets/map/escalier.png");
}

/**
* @brief To free the background map and escalier .
* @param map the background
* @param escalier
* @return Nothing
*/
void freesurfacemap(map *map,escalier *escalier)
{
SDL_FreeSurface(map->fond);
SDL_FreeSurface(map->fond2);
SDL_FreeSurface(escalier->fond);
}

/**
* @brief To show the background map .
* @param map the background
* @param camera
* @param ecran (the screen)
* @return Nothing
*/
void afficherfond(map map,SDL_Rect *camera,SDL_Surface *ecran)
{
SDL_BlitSurface(map.fond,camera, ecran,&map.position);
}





