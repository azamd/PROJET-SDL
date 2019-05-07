#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "chrono.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>


void afficher_chrono()
{

 SDL_Surface *ecran = NULL, *texte = NULL,*image;
    SDL_Rect position,positionecran;
    SDL_Event event;
    TTF_Font *police = NULL; 
    SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255, 255, 255}; //couleur
    int continuer = 1;
    int tempsActuel = 0, tempsPrecedent = 0, compteur = 0,fps=0,fpm=0,fph=0; //calcul fps
    char temps[30] = ""; 
   
    float dt;

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    ecran = SDL_SetVideoMode(900, 425, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Affichage chronometre", NULL);


image=IMG_Load("s.png"); // chargement du background
positionecran.x=0;
positionecran.y=0;
positionecran.w=image->w;



    police = TTF_OpenFont("arial.ttf", 25); //chargement type du police


    tempsActuel = SDL_GetTicks();
    sprintf(temps, "Temps : %d", compteur);
    
    texte = TTF_RenderText_Blended(police, temps, couleurBlanche); // affichage du police

    while (continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

        tempsActuel = SDL_GetTicks();
          dt=tempsActuel - tempsPrecedent;
         
      if ( dt >= 1000) 
        {
          compteur += 1000; 
          fps=compteur/1000;
           
               
             if (fps>59)
                 { fpm=(fps/60);
                 
                   
                   if(fpm>59)
                      fph=(fpm/60);
                  
                  
                 }
             
           
           

              
            sprintf(temps,"Temps: %d :%d :%d",fph,fpm,fps-(60*fpm));
           SDL_FreeSurface(texte);

             texte = TTF_RenderText_Blended(police, temps, couleurBlanche);


            tempsPrecedent = tempsActuel; 
        }

        position.x =220;
        position.y = 0;

        SDL_BlitSurface(image,NULL,ecran,&positionecran);
        SDL_BlitSurface(texte, NULL, ecran, &position); 
        SDL_SetColorKey(texte,SDL_SRCCOLORKEY,SDL_MapRGB(texte->format,0,0,0));      
        SDL_Flip(ecran);

    }

    TTF_CloseFont(police);
    TTF_Quit();

    SDL_FreeSurface(texte);
    SDL_Quit();

  
}
