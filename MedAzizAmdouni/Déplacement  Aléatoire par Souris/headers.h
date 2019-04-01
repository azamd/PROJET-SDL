#ifndef FONCTION_H_
#define FONCTION_H_
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>


void moving_right(SDL_Rect *positionmilieu,SDL_Rect *posfond,SDL_Surface *imgfond,SDL_Surface * screen,SDL_Surface *imgperso);

void moving_left(SDL_Rect *positionmilieu,SDL_Rect *posfond,SDL_Surface *imgfond , SDL_Surface *screen,SDL_Surface *imgperso);

void gravity(SDL_Rect *positionmilieu,SDL_Rect *posfond,SDL_Surface *imgfond , SDL_Surface *screen,SDL_Surface *imgperso);

void mousemove(SDL_Rect *positionmilieu,SDL_Rect *posfond,SDL_Surface *imgfond , SDL_Surface *screen,SDL_Surface *imgperso);

void jump(SDL_Rect *positionmilieu,SDL_Rect *posfond,SDL_Surface *imgfond, SDL_Surface *screen,SDL_Surface *imgperso);

#endif
