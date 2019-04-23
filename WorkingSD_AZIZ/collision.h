#ifndef COLLISION_H_
#define COLLISION_H_



Uint32 getpixel(SDL_Surface *surface, int x, int y);
SDL_Rect collision(SDL_Rect camera,perso perso);
int collisionescalier(perso perso,escalier escalier,SDL_Rect camera);
void collisionennemi(perso *perso,ennemis *ennemi,SDL_Rect *camera,vie *vie);

#endif 
