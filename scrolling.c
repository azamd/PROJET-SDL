#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

int main()
{
SDL_Surface *ecran = NULL, *imageDeFond = NULL,*imageDePerso=NULL;//declaration des differents pointeurs
int x=0,i;


    SDL_Rect positionFond ,positionmilieu;
   //definition des coordonnées ( sur axe (x,y) et largeur + hauteur)
    positionFond.x = 0;
    positionFond.y = 0;
    positionFond.h =1000;
    positionFond.w =800;

    

    //definition des coordonnées du milieu
    positionmilieu.x = 800/ 2 - 50 / 2;
    positionmilieu.y = 420 ;
     SDL_Init(SDL_INIT_VIDEO);//initialisation video de la bib SDL

    ecran = SDL_SetVideoMode(800,600, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);//choisir le mode d'affichage (hauteur+largeur)
    SDL_WM_SetCaption("SCROLLING", NULL);//titre choisi pour la fenetre

    
    imageDeFond = IMG_Load("backg.png");//chargement de l'image
    imageDePerso = IMG_Load("box.png");//chargement de l'image
    

  SDL_BlitSurface(imageDeFond,&positionFond, ecran, NULL);//chargement du background dans une position précie
  SDL_BlitSurface(imageDePerso,NULL, ecran, &positionmilieu);//chargement de l'image du personnage
  SDL_Flip(ecran);//mise a jour
  
 if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)// initiliser mixer
    {
        printf("%s",Mix_GetError());
    }
    Mix_Music *musique;//pointeur musique 
    Mix_AllocateChannels(20);//
    musique = Mix_LoadMUS("musique.mp3");//chargement musique
    Mix_PlayMusic(musique, -1);//repeter  music (boucle infinie)
    Mix_VolumeMusic(MIX_MAX_VOLUME / 1);//MIX_MAX_VOLUME se defere de chaque pc (peut etre 1 ou 2 seulement)

   
    int continuer = 1;
    SDL_Event event;//declaration des evenements
    SDL_EnableKeyRepeat(10, 10);
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT: //quiter le programme si on appuit sur le bouton (X) de fermiture
                continuer = 0;
                break;
            case SDL_KEYDOWN: //si on appuit sur un bouton du clavier

        switch(event.key.keysym.sym)

        {

            case SDLK_RIGHT: // appui sur la Flèche droite
            	
                if  (positionmilieu.x>=516 && positionFond.x<=7200)
        
            positionFond.x += 10;// la position de la limite de l'image du fond avance en vitesse =10
        else if (positionmilieu.x<=750) 
            positionmilieu.x +=20;//la position milieu avance en vitesse =20
            
       
                SDL_BlitSurface(imageDeFond,&positionFond, ecran, NULL);//mise a jour du position de l'image du fond
                SDL_BlitSurface(imageDePerso,NULL, ecran, &positionmilieu);//mise a jour du position de l'image du personnage en position milieu
                
    SDL_Flip(ecran); //mise a jour

                break;

            case SDLK_LEFT: // appui sur la Flèche gauche
            	if (positionmilieu.x<=258 && positionFond.x>=0)
        
            positionFond.x -= 10; //la position de la limite de l'image du fond recule en vitesse =10
      else if (positionmilieu.x>=0)
      positionmilieu.x -= 20;//la position milieu avance en vitesse =20
SDL_BlitSurface(imageDeFond,&positionFond, ecran, NULL);//mise a jour du position de l'image du fond
      SDL_BlitSurface(imageDePerso,NULL, ecran, &positionmilieu);//mise a jour du position de l'image du personnage en position milieu
                
    SDL_Flip(ecran);//mise a jour

                break;

   
        }

        break;    
        }

       
        
    SDL_Flip(ecran);//mise a jour
    }


    SDL_FreeSurface(imageDeFond); //liberation de l'espace memoire

    SDL_Quit();//arret du programme
    return EXIT_SUCCESS;
}
