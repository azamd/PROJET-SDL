#include "fonction.h"

Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        return *p;
        break;

    case 2:
        return *(Uint16 *)p;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
        break;

    case 4:
        return *(Uint32 *)p;
        break;

    default:
        return 0;       /* shouldn't happen, but avoids warnings */
    }
}

SDL_Rect collision(SDL_Rect camera,perso perso)
{
if(camera.x<0)
{
camera.x=0;
}

if(camera.x>6460)
{
camera.x=6460;
}

return camera ;
}


int collisionescalier(perso perso,escalier escalier,SDL_Rect camera)
{
Uint32 Blanc = SDL_MapRGB(escalier.fond->format,255,255,255);
if(getpixel(escalier.fond,camera.x+perso.position.x,perso.position.y+124) == Blanc)
{
return 1;
}
return 0;
}

void collisionennemi(perso *perso,ennemis *ennemi,SDL_Rect *camera,vie *vie)
{
if(((((perso->position.x+perso->fond1->w > ennemi->position.x)&&(perso->position.x+perso->fond1->w < ennemi->position.x+ennemi->fond1->w))||((perso->position.x < ennemi->position.x+ennemi->fond1->w)&&(perso->position.x > ennemi->position.x)))&&perso->position.y==255&&ennemi->position.y == 240)||((((perso->position.x+perso->fond1->w > ennemi->position.x)&&(perso->position.x+perso->fond1->w < ennemi->position.x+ennemi->fond1->w))||((perso->position.x < ennemi->position.x+ennemi->fond1->w)&&(perso->position.x > ennemi->position.x)))&&perso->position.y==435&&ennemi->position.y == 420))
{
ennemi->position.x = 1001 ;
perso->position.x = 100 ;
perso->position.y = 435 ;
camera->x=0;
vie->nb--;
}
}


