#ifndef MAP_H_
#define MAP_H_
typedef struct map
{
	SDL_Rect position;
	SDL_Surface *fond;
	SDL_Surface *fond2;
	SDL_Surface *fond3;
	SDL_Surface *ff1;
	SDL_Surface *ff2;
	SDL_Surface *ff3;
	SDL_Surface *ff4;
	SDL_Surface *ff5;
	SDL_Surface *ff6;
	SDL_Surface *ff7;
	SDL_Surface *ff8;
	SDL_Surface *ff9;
	SDL_Surface *ff10;
}map;

typedef struct escalier
{
	SDL_Rect position;
	SDL_Surface *fond;
}escalier;

void initialiserfond(map *map);
void initialiserfond2(map *map);
void initialiserfond3(map *map);
void freesurfacemap(map *map,escalier *escalier);
void initialiserescalier(escalier *escalier);
void afficherfond(map map,SDL_Rect *camera,SDL_Surface *ecran);
void afficherfond2(map map,SDL_Rect *camera,SDL_Surface *ecran);

#endif 
