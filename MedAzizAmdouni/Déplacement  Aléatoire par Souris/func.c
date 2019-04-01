#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "headers.h"

void moving_right(SDL_Rect *positionmilieu,SDL_Rect *posfond,SDL_Surface *imgfond , SDL_Surface *screen,SDL_Surface *imgperso){
 if  (positionmilieu->x>=516 && posfond->x<=1180)
            posfond->x += 10;
        else if (positionmilieu->x<=750) 
            positionmilieu->x +=20;
            SDL_BlitSurface(imgfond,posfond,screen, NULL);
            SDL_BlitSurface(imgperso,NULL, screen, positionmilieu);
    SDL_Flip(screen); 
}

void moving_left(SDL_Rect *positionmilieu,SDL_Rect *posfond,SDL_Surface *imgfond , SDL_Surface *screen,SDL_Surface *imgperso){
if (positionmilieu->x<=258 && posfond->x>=10)
            posfond->x -= 10;
      else if (positionmilieu->x>=0)
      positionmilieu->x -= 20;
SDL_BlitSurface(imgfond,posfond, screen, NULL);
SDL_BlitSurface(imgperso,NULL, screen, positionmilieu);
               SDL_Flip(screen);
}

void jump(SDL_Rect *positionmilieu,SDL_Rect *posfond,SDL_Surface *imgfond , SDL_Surface *screen,SDL_Surface *imgperso){
for(int i=0;i<10;i++){
positionmilieu->y-=10;
            
SDL_BlitSurface(imgfond,posfond,screen, NULL);
      SDL_BlitSurface(imgperso,NULL,screen, positionmilieu);
    SDL_Flip(screen);
}}

void gravity(SDL_Rect *positionmilieu,SDL_Rect *posfond,SDL_Surface *imgfond , SDL_Surface *screen,SDL_Surface *imgperso){
 while(positionmilieu->y<420){
positionmilieu->y+=5;
      SDL_BlitSurface(imgfond,posfond,screen,NULL);
      SDL_BlitSurface(imgperso,NULL,screen,positionmilieu);     
    SDL_Flip(screen);
}
}

void mousemove(SDL_Rect *positionmilieu,SDL_Rect *posfond,SDL_Surface *imgfond , SDL_Surface *screen,SDL_Surface *imgperso){
int mousex=0,mousey=0;
SDL_GetMouseState(&mousex,&mousey);

if(mousex>positionmilieu->x){
if  (positionmilieu->x>=516 && posfond->x<=1180)
        
            posfond->x += 10;
        else if (positionmilieu->x<=750) 
            positionmilieu->x +=20;
            SDL_BlitSurface(imgfond,posfond,screen, NULL);
            SDL_BlitSurface(imgperso,NULL,screen, positionmilieu);
    SDL_Flip(screen);
}else{
if (positionmilieu->x<=258 && posfond->x>=10)
        
            posfond->x -= 10; 
      else if (positionmilieu->x>=0)
      positionmilieu->x -= 20;
      SDL_BlitSurface(imgfond,posfond,screen,NULL);
      SDL_BlitSurface(imgperso,NULL,screen, positionmilieu);
                
    SDL_Flip(screen);
    }
}
