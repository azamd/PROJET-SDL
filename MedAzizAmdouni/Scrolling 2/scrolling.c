#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "scrolling.h"


void scrolling(SDL_Surface *screen,SDL_Surface *imgfond,SDL_Surface *imgperso,int running,SDL_Rect posfond,SDL_Rect positionmilieu)
{

int x=0,i;

   //definition des coordonnées ( sur axe (x,y) et largeur + hauteur)
    posfond.x = 0;
    posfond.y = 0;
    posfond.h =1000;
    posfond.w =800;

    

    //definition des coordonnées du milieu
    positionmilieu.x = 800/ 2 - 50 / 2;
    positionmilieu.y = 420 ;
     SDL_Init(SDL_INIT_VIDEO);//initialisation video de la bib SDL

    screen = SDL_SetVideoMode(800,600, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);//choisir le mode d'affichage (hauteur+largeur)
   

    
    imgfond = IMG_Load("backg.png");//chargement de l'image
    imgperso = IMG_Load("box.png");//chargement de l'image
    

  SDL_BlitSurface(imgfond,&posfond,screen, NULL);//chargement du background dans une position précie
  SDL_BlitSurface(imgperso,NULL,screen, &positionmilieu);//chargement de l'image du personnage
  SDL_Flip(screen);//mise a jour
  
 if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)// initiliser mixer
    {
        printf("%s",Mix_GetError());
    }
    Mix_Music *musique;//pointeur musique 
    Mix_AllocateChannels(20);//
    musique = Mix_LoadMUS("musique.mp3");//chargement musique
    Mix_PlayMusic(musique, -1);//repeter  music (boucle infinie)
    Mix_VolumeMusic(MIX_MAX_VOLUME / 1);//MIX_MAX_VOLUME se defere de chaque pc (peut etre 1 ou 2 seulement)

   
    SDL_Event event;//declaration des evenements
    SDL_EnableKeyRepeat(10, 10);
 
    while (running)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT: //quiter le programme si on appuit sur le bouton (X) de fermiture
                running = 0;
                break;
            case SDL_KEYDOWN: //si on appuit sur un bouton du clavier

        switch(event.key.keysym.sym)

        {

            case SDLK_RIGHT: // appui sur la Flèche droite
            	
                if  (positionmilieu.x>=516 && posfond.x<=7200)
        
            posfond.x += 10;// la position de la limite de l'image du fond avance en vitesse =10
        else if (positionmilieu.x<=750) 
            positionmilieu.x +=20;//la position milieu avance en vitesse =20
            
       
                SDL_BlitSurface(imgfond,&posfond,screen, NULL);//mise a jour du position de l'image du fond
                SDL_BlitSurface(imgperso,NULL,screen, &positionmilieu);//mise a jour du position de l'image du personnage en position milieu
                
    SDL_Flip(screen); //mise a jour

                break;

            case SDLK_LEFT: // appui sur la Flèche gauche
            	if (positionmilieu.x<=258 && posfond.x>=0)
        
            posfond.x -= 10; //la position de la limite de l'image du fond recule en vitesse =10
      else if (positionmilieu.x>=0)
      positionmilieu.x -= 20;//la position milieu avance en vitesse =20

SDL_BlitSurface(imgfond,&posfond, screen, NULL);//mise a jour du position de l'image du fond
      SDL_BlitSurface(imgperso,NULL,screen, &positionmilieu);//mise a jour du position de l'image du personnage en position milieu
                
    SDL_Flip(screen);//mise a jour

                break;

   
        }

        break;    
        }

       
        
    SDL_Flip(screen);//mise a jour
    }
}
