#include "fonction.h"

void initialiserfond(map *map)
{
map->position.x = 0 ;
map->position.y = 0 ;
map->fond = IMG_Load("../game/map/map.png");
map->fond2 = IMG_Load("../game/map/map2.png");
}

void initialiserfond2(map *map)
{
map->position.x = 0 ;
map->position.y = 0 ;
map->fond = IMG_Load("../game/map/map2.jpg");
map->fond2 = IMG_Load("../game/map/mapp2.png");
map->fond3 = IMG_Load("../game/map/mappp2.png");
map->ff1 = IMG_Load("../game/map/ff1.png");
map->ff2 = IMG_Load("../game/map/ff2.png");
map->ff3 = IMG_Load("../game/map/ff3.png");
map->ff4 = IMG_Load("../game/map/ff4.png");
map->ff5 = IMG_Load("../game/map/ff5.png");
map->ff6 = IMG_Load("../game/map/ff6.png");
map->ff7 = IMG_Load("../game/map/ff7.png");
map->ff8 = IMG_Load("../game/map/ff8.png");
map->ff9 = IMG_Load("../game/map/ff9.png");
map->ff10 = IMG_Load("../game/map/black.png");
}

void initialiserfond3(map *map)
{
map->position.x = 0 ;
map->position.y = 0 ;
map->fond = IMG_Load("../game/map/map3.png");
map->fond2 = IMG_Load("../game/map/mapp3.png");
}

void initialiserescalier(escalier *escalier)
{
escalier->position.x = 0 ;
escalier->position.y = 0 ;
escalier->fond = IMG_Load("../game/map/escalier.png");
}

void freesurfacemap(map *map,escalier *escalier)
{
SDL_FreeSurface(map->fond);
SDL_FreeSurface(map->fond2);
SDL_FreeSurface(escalier->fond);
}

void afficherfond(map map,SDL_Rect *camera,SDL_Surface *ecran)
{
SDL_BlitSurface(map.fond,camera, ecran,&map.position);
}





