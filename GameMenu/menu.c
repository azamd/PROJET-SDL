
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>


int main()
{
    int i=0;
    SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL
    //declaration des pointeurs: chaque pointeur correspond a une image 
    SDL_Surface *ecran =NULL,*imageDeFond = NULL,*image=NULL,*image2=NULL,*image3=NULL,*image4=NULL,*image5=NULL; 
    ecran=SDL_SetVideoMode(900, 420, 32, SDL_HWSURFACE); // choisir la mode d'affichage du fenetre + definition de l'hauteur et la largeur du fenetre.
    SDL_Rect positionFond,positionim,positionim2,positionim3,positionim4,positionim5;//declaration des cordonnées des differentes images
    SDL_WM_SetCaption("THE ETERNAL STONES", NULL);// nom choisi pour la fenetre 
    
   //precision des positions des differentes images.
    positionFond.x =  0 ;
    positionFond.y =  0 ;
    positionim.x =0 ;
    positionim.y = 0 ;
    positionim2.x =0 ;
    positionim2.y = 0 ;
    positionim3.x =0 ;
    positionim3.y = 0 ;
    positionim4.x =0 ;
    positionim4.y = 0 ;
    positionim5.x =0 ;
    positionim5.y = 0 ;
    imageDeFond = IMG_Load("Menu.png");// chargement du l'image du fond (background)
    image= IMG_Load("solo.png");//bouton solo s'allume
    image2= IMG_Load("multiplayer.png");//bouton multiplayer s'allume
    image3= IMG_Load("settings.png");//bouton settings s'allume
    image4= IMG_Load("credits.png");//bouton credits s'allume
    image5= IMG_Load("exit.png");//bouton exit s'allume
    SDL_Flip(ecran);// mise a jour
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)// initiliser mixer
    {
        printf("%s",Mix_GetError());
    }
    Mix_Music *musique;//pointeur sur musique du jeu
    Mix_AllocateChannels(20);
    musique = Mix_LoadMUS("music.mp3");//chargement du musique du jeu
    Mix_PlayMusic(musique, -1);//repeter la musique dujeu (boucle infinie)
    Mix_VolumeMusic(MIX_MAX_VOLUME / 1);//MIX_MAX_VOLUME se defere de chaque pc
    Mix_Chunk *MB;//pointeur music boutton(chunk se defere de format) chunk pour format wav ; Music pour format mp3
    MB = Mix_LoadWAV("sound.wav");// chargement du son du clique des bouttons.
    SDL_Event event;//declaration des evenements
    int continuer = 1;//si continuer=1 il reste dans la boucle while sinon il quitte la boucle

    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);//affichage de menu (affichage de la 1ere image sur l'ecran avec une position definie)

    while (continuer)//continuer==1
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT://appui sur le bouton de fermiture de la fenetre bouton(X)
            continuer = 0;//arret du programme
            break;
        case SDL_MOUSEBUTTONDOWN:// en cas d'appui sur un bouton de souris
           if (event.button.button == SDL_BUTTON_LEFT)// si on appuie sur le bouton gauche de la souris
            {
                 //precision de mouvement du curseur par rapport au dimensions des boutons
                if ( event.button.x >20 && event.button.y >240 && event.button.x < 192 && event.button.y <250)//les cordonnees ou on appuie par la souris(cordonnee de 'solo')
                {
                    SDL_BlitSurface(image,NULL, ecran, &positionim);//bouton solo s'allume (affichage de image 2)
                    SDL_Flip(ecran);//mise a jour
                    SDL_Delay(400);//delai d'allumage du bouton en ms
                    Mix_PlayChannel(1, MB, 0);
                }

                if ( event.button.x >20 && event.button.y >260 && event.button.x <90 && event.button.y <280)
                {
                    SDL_BlitSurface(image2,NULL, ecran, &positionim2);//bouton multiplayer s'allume (affichage de image 3)
                    SDL_Flip(ecran);//mise a jour
                    SDL_Delay(400);//delai d'allumage du bouton en ms
                    Mix_PlayChannel(1, MB, 0);
                   
                }
                if ( event.button.x >20 && event.button.y >290 && event.button.x < 190 && event.button.y <310)

                {
                    SDL_BlitSurface(image3,NULL, ecran, &positionim3);//bouton settings s'allume
                    SDL_Flip(ecran);//mise a jour
                    SDL_Delay(400);//delai d'allumage du bouton
                    Mix_PlayChannel(1, MB, 0);

                }
                if ( event.button.x >20 && event.button.y >330 && event.button.x < 135 && event.button.y <345)
                {
                    SDL_BlitSurface(image4,NULL, ecran, &positionim4);//bouton credits s'allume
                    SDL_Flip(ecran);//mise a jour
                    SDL_Delay(400);//delai d'allumage du bouton
                    Mix_PlayChannel(1, MB, 0);
                   
                }
             if ( event.button.x >20 && event.button.y >353 && event.button.x < 70 && event.button.y <365)
                {
                    SDL_BlitSurface(image5,NULL, ecran, &positionim5);//bouton exit s'allume
                    SDL_Flip(ecran);//mise a jour
                    SDL_Delay(400);//delai d'allumage du bouton
                    Mix_PlayChannel(1, MB, 0);
                    continuer=0;//arret du programme lors de l'appui a 'Exit' par le bouton gauche de la souris
                }
            }
            break;

        case SDL_KEYDOWN://si on appuie sur une touche du clavier
            switch(event.key.keysym.sym)
            {

            case SDLK_RETURN: //bouton entrer
                if (i==1)
                {

                }
                else if (i==2)
                {
                }
                else if (i==3)
                {

                }
                else if (i==4)
                {
                   
                }
                else if (i==5)
                {
                    continuer=0;//arret du programme lors de l'appui a 'Exit' par touche 'Entrer' du clavier
                }

                break;

            case SDLK_DOWN://si on appuie sur le bouton bas.
                i++;//incrementation par 1;
                if(i==6)
                {
                    i=1;
                }
                if(i==1)
                {
                    SDL_BlitSurface(image,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                    Mix_PlayChannel(1, MB, 0);
                }
                if(i==2)
                {
                    SDL_BlitSurface(image2,NULL, ecran, &positionim2);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                    Mix_PlayChannel(1, MB, 0);
                }
                if(i==3)
                {
                    SDL_BlitSurface(image3,NULL, ecran, &positionim3);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
Mix_PlayChannel(1, MB, 0);

                }
                if(i==4)
                {
                    SDL_BlitSurface(image4,NULL, ecran, &positionim4);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
Mix_PlayChannel(1, MB, 0);
                }
                if(i==5)
                {
                    SDL_BlitSurface(image5,NULL, ecran, &positionim5);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
Mix_PlayChannel(1, MB, 0);
                 }
                break;
            case SDLK_UP: //si on appuie sur le bouton haut 
                i--;
                if(i<0)
                {
                    i=6;
                }
                if(i==6)
                {
                    i=5;
                }
                if(i==1)
                {
                    SDL_BlitSurface(image,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                    Mix_PlayChannel(1, MB, 0);
                }
                if(i==2)
                {
                    SDL_BlitSurface(image2,NULL, ecran, &positionim2);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                    Mix_PlayChannel(1, MB, 0);
                }
                if(i==3)
                {
                    SDL_BlitSurface(image3,NULL, ecran, &positionim3);
                    SDL_Flip(ecran);
                    SDL_Delay(500) ;  
                    Mix_PlayChannel(1, MB, 0);
                }
                if(i==4)
                {
                    SDL_BlitSurface(image4,NULL, ecran, &positionim4);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                    Mix_PlayChannel(1, MB, 0);
                }
                 if(i==5)
                {
                    SDL_BlitSurface(image5,NULL, ecran, &positionim5);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                    Mix_PlayChannel(1, MB, 0);
                }
                break;
            }
        }
          
        SDL_Flip(ecran);//mise a jours
    }
    Mix_FreeMusic(musique);//liberation d'espace memoire
    Mix_CloseAudio();//sound off
    SDL_Quit(); // Arrêt de la SDL


    return EXIT_SUCCESS; // Fermeture du programme
}






