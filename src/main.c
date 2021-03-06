#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "SDL/SDL_gfxPrimitives.h"
#include "SDL/SDL_mixer.h"
#include "submenu.h"
#include "fonction.h"
#include "animation.h"
int main(int argc, char *argv[])

{
    SDL_Surface *ecran = NULL, *imageDeFond = NULL,*solo = NULL,*multi = NULL,*sett = NULL,*cred = NULL,*exit = NULL,*Volume = NULL,*Menu0 = NULL,*Menu1 = NULL, *Menu2 = NULL;
    SDL_Rect position ;
int running=1,i=0,j=4,keyboard=0,mouse=1,controller=0,k=3 ,fr=0,actuel=0,prec=0,frr=0 ; ;
Objet volume0 ,volume25,volume50,volume75,volume100,sous_menumouse,sous_menukey,sous_menucontroller ;

    Mix_Music *music ;

    position.x = 0 ;
    position.y = 0 ;

    int continuer = 1,continuer0= 1 ;//Game Menu ON/OFF | Options Menu ON/OFF
    int so=0,mp=0,cr=0,se=0,ex=0,b=0; //so: solo | mp: multiplayer | cr: credits | se: settings | ex: exit
    int z =128 ;     //z: main volume
    int x = 0 ;    //x: choix

    SDL_Event event;
    Mix_Chunk *MB;  // button
    MB = Mix_LoadWAV("../assets/sfx/button.wav");// clique de bouton

    ecran = SDL_SetVideoMode(900,425, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("THE ETERNAL STONES ", NULL);
	

Objett tab [200],tab2[200] ;


	setup (&sous_menukey,&sous_menumouse ,&volume100,&volume75,&volume50,&volume25,&volume0,&sous_menucontroller) ;

    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    {
        printf("%s",Mix_GetError());
    }

    music = Mix_LoadMUS("../assets/sfx/musique.mp3");
    Mix_PlayMusic(music,-1);


    SDL_ShowCursor(SDL_ENABLE);

    imageDeFond = IMG_Load("../assets/menu/Menu.png");

    solo=IMG_Load("../assets/menu/solo.png") ;
    multi=IMG_Load("../assets/menu/multi.png") ;
    sett=IMG_Load("../assets/menu/sett.png") ;
    cred=IMG_Load("../assets/menu/cred.png") ;
    exit=IMG_Load("../assets/menu/exit.png") ;

    Menu0 = IMG_Load("../assets/menu/Menu0.png");
    Menu1 = IMG_Load ("../assets/menu/Menu1.png");
    Menu2 = IMG_Load("../assets/menu/Menu2.png");

    Volume=IMG_Load("../assets/menu/volume.png") ;

    SDL_EnableKeyRepeat(100, 10);

  load_transition1(tab) ;
  //load_transition(tab2) ;
    while (continuer)
    {
	actuel = SDL_GetTicks();
        ecran = SDL_SetVideoMode(900, 425, 32, SDL_HWSURFACE | SDL_DOUBLEBUF /*| SDL_RESIZABLE | SDL_FULLSCREEN */);


        SDL_WaitEvent(&event);

        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                // coords solo mode button
                if ( event.button.x >10 && event.button.y >220 && event.button.x < 300 && event.button.y <255)
                {
                    so=1; //solo on
                    x = 1 ;
                    mp=0 ;
                    se=0 ;
                    cr=0 ;
                    ex=0;
                    jeux(1); //save option ON/OFF
                    Mix_PlayChannel(1, MB, 0);
                }

                if ( event.button.x >10 && event.button.y >257 && event.button.x <190 && event.button.y <280)
                {
                    x=2;
                    mp=1; //multiplayer on
                    so=0 ;
                    cr=0 ;
                    se=0 ;
                    ex=0;
                    Mix_PlayChannel(1, MB, 0);
                }
                if ( event.button.x >10 && event.button.y >282 && event.button.x < 148 && event.button.y <320)

                {
                    x=3;
                    se=1; //settings on
                    so=0 ;
                    mp=0 ;
                    cr=0 ;
                    ex=0;
                    Mix_PlayChannel(1, MB, 0);

                }
                if ( event.button.x >10 && event.button.y >322 && event.button.x < 125 && event.button.y <347)
                {
                    x=4;
                    so=0 ;
                    mp=0 ;
                    se=0 ;
                    cr=1 ; //credits on
                    ex=0;
                    Mix_PlayChannel(1, MB, 0);
                }
                if ( event.button.x >10 && event.button.y >347 && event.button.x < 75 && event.button.y <365)
                {
                    cr=0;
                    so=0 ;
                    mp=0 ;
                    se=0 ;
                    ex=1; //exit on
                    x=5;
                    continuer=0;
                    Mix_PlayChannel(1, MB, 0);
                }
            }
            break;

        case SDL_KEYDOWN:

            switch (event.key.keysym.sym)
            {

            case SDLK_ESCAPE:
                continuer=0 ;
                
                break ;

            case SDLK_UP:

                if (x==3)
                {
                    x = 2 ;
                    mp=1; //multiplayer on
                    so=0 ;
                    cr=0 ;
                    se=0 ;
                    ex=0;
                    Mix_PlayChannel(1, MB, 0);
                    break ;
                }
                if (x==4)
                {
                    se=1; //settings on
                    x = 3 ;
                    so=0 ;
                    mp=0 ;
                    cr=0 ;
                    ex=0;
                    Mix_PlayChannel(1, MB, 0);
                    break ;
                }
                if (x==1)
                {
                    cr=0;
                    x = 5 ;
                    so=0 ;
                    mp=0 ;
                    se=0 ;
                    ex=1; //exit on
                    Mix_PlayChannel(1, MB, 0);
                    break ;
                }
                if (x==2)
                {
                    so=1; //solo on
                    x = 1 ;
                    mp=0 ;
                    se=0 ;
                    cr=0 ;
                    ex=0;
                    Mix_PlayChannel(1, MB, 0);
                    break ;
                }
                if (x==5)
                {
                    so=0 ;
                    x = 4 ;
                    mp=0 ;
                    se=0 ;
                    cr=1 ;
                    ex=0;
                    Mix_PlayChannel(1, MB, 0);
                    break ;
                }

            case SDLK_DOWN:

                if (x==5)
                {
                    so=1 ;
                    x = 1 ;
                    mp=0 ;
                    se=0 ;
                    cr=0 ;
                    ex=0;
                    Mix_PlayChannel(1, MB, 0);
                    break ;
                }
                if (x==1)
                {
                    mp=1 ;
                    x = 2 ;
                    so=0 ;
                    se=0 ;
                    cr=0 ;
                    ex=0;
                    Mix_PlayChannel(1, MB, 0);
                    break ;
                }
                if (x==2)
                {
                    se=1 ;
                    x = 3 ;
                    so=0 ;
                    mp=0 ;
                    cr=0 ;
                    ex=0;
                    break ;
                }
                if (x==3)
                {
                    so= 0;
                    x = 4 ;
                    mp=0 ;
                    se=0 ;
                    cr=1 ;
                    ex=0;
                    break ;
                }
                if (x==4)
                {
                    so= 0;
                    x = 5 ;
                    mp=0 ;
                    se=0 ;
                    cr=0 ;
                    ex=1;
                    break ;
                }
            case SDLK_KP1:
                so=1 ;
                mp=0 ;
                se=0 ;
                cr=0 ;
                ex=0;
                x=1;
                break;
            case SDLK_KP2:
                mp=1 ;
                so=0 ;
                se=0 ;
                cr=0 ;
                ex=0;
                x=2;
                break;
            case SDLK_KP3:
                se=1 ;
                so=0 ;
                mp=0 ;
                cr=0 ;
                ex=0 ;
                x=3;
                break;
            case SDLK_KP4:
                cr= 1;
                so=0 ;
                mp=0 ;
                se=0 ;
                ex=0;
                x=4;
                break;
            case SDLK_KP5:
                cr=0;
                so=0 ;
                mp=0 ;
                se=0 ;
                ex=1;
                x=5;
                     
            case SDLK_RETURN :
                switch(x)
                {
                case 1:
              
                   continuer0 = 1 ;
                while(continuer0)
                 {
                  SDL_WaitEvent(&event);
        switch(event.type)
        { 
          
           SDL_BlitSurface(Menu0,NULL, ecran, &position);
         
          case SDLK_ESCAPE:
                continuer=0 ;
                
        case SDL_MOUSEBUTTONDOWN:
           if (event.button.button == SDL_BUTTON_LEFT)
            {

                if ( event.button.x >10 && event.button.y >220 && event.button.x < 300 && event.button.y <255)
                {
                    SDL_BlitSurface(Menu1,NULL, ecran, &position);
                    SDL_Flip(ecran);
                    //SDL_Delay(400);
                    jeux(0);
                }

                if ( event.button.x >10 && event.button.y >257 && event.button.x <190 && event.button.y <280)
                {
                    SDL_BlitSurface(Menu2,NULL, ecran, &position);
                    SDL_Flip(ecran);
                    //SDL_Delay(400);
                  jeux(1);
                }
                
                
                  case SDL_KEYDOWN://appui sur bouton
            switch(event.key.keysym.sym)
            {

            case SDLK_RETURN: //bouton entrer
                if (b==1)
                {
                 jeux(0);
                }
                else if (b==2)
                {
                 jeux(1);
                }
                

                
                case SDLK_DOWN://appui sur le bouton bas
                b++;
                if(b==3)
                {
                    b=1;
                }
                if(b==1)
                {
                    SDL_BlitSurface(Menu1,NULL, ecran, &position);
                    SDL_Flip(ecran);
                    //SDL_Delay(500);
                    
                }
                if(b==2)
                {
                    SDL_BlitSurface(Menu2,NULL, ecran, &position);
                    SDL_Flip(ecran);
                    //SDL_Delay(500);
                    
                }
                
                case SDLK_UP://appui sur le bouton haut
                b--;
                if(b<0)
                {
                    b=3;
                }
                if(b==3)
                {
                    b=2;
                }
                if(b==1)
                {
                    SDL_BlitSurface(Menu1,NULL, ecran, &position);
                    SDL_Flip(ecran);
                    //SDL_Delay(500);
                   // Mix_PlayChannel(1, MB, 0);
                }
                if(b==2)
                {
                    SDL_BlitSurface(Menu2,NULL, ecran, &position);
                    SDL_Flip(ecran);
                    //SDL_Delay(500);
                    //Mix_PlayChannel(1, MB, 0);
                }
                } 
                break;
			}
        }
    }break;             
                case 2 : //pour multiplayer
                    

                    break ;
                case 4 :
                     printf("THE ETERNAL STONES is a 2D SDL Video Game devolopped by CYBERPUNK Team 2019. \n");
                    break ;
                case 5 :
                     continuer0 =0;
                     continuer = 0;
                     printf("Thanks for playing. \n");
                     
                            break ;
                case 3 :
                    continuer0 = 1 ;
                    while (continuer0)
                    {
                        SDL_WaitEvent(&event);
                        switch(event.type)
                        {
                        case SDL_QUIT:
                            continuer0 = 0;
                            continuer = 0 ;
                            break;

                        case SDL_KEYDOWN:

                            switch (event.key.keysym.sym)
                            {
                            case SDLK_ESCAPE:
                                continuer0=0 ;
                                break ;
				                case SDLK_RIGHT :
			z = z + 2 ;
                  if(i==1)
                  {
                    j++ ;
                    if(j>4)
                    j=4 ;
                  }
                  else if (i==0)
                  {
                   k++ ;
                   if(k>3)
                    k=1 ;
                  }
                 break ;
                 case SDLK_LEFT :
			z = z - 2 ;
                 if(i)
                 {
                    j-- ;
                    if(j<0)
                    j=0 ;   
                 } 
                  else if (i==0)
                  {
                    k -- ;
                   if(k<1)
                    k=3 ;
                  }             
                 break ;
                 case SDLK_UP :
                   i--  ;
                   if(i<0)
                   i=1 ;
                 break ;
                 case SDLK_DOWN :
                   i ++ ;
                   if(i>1)
                   i=0 ;
                  break ;
                            case SDLK_KP_PLUS :
                                z = z + 2 ;
                                break ;
                            case SDLK_KP_MINUS :
                                z = z - 2 ;
                                break ;
                            case SDLK_m :
                                switch(x)
                                {
                                case 4:
                                    Mix_PauseMusic();
                                    x=3;
                                    break ;
                                case 3:
                                    Mix_ResumeMusic();
                                    x=4 ;
                                    break ;
                                }
                                break ;
                            }
                        }

                        Mix_VolumeMusic(z);

 if(i==0)
  {
    if(k==2)
    SDL_BlitSurface(sous_menukey.img,NULL,ecran,&(sous_menukey.pos)) ;
    else if (k==1)
    SDL_BlitSurface(sous_menumouse.img,NULL,ecran,&(sous_menumouse.pos)) ;  
    else if (k==3) 
    SDL_BlitSurface(sous_menucontroller.img,NULL,ecran,&(sous_menucontroller.pos)) ;  

  }
  else if(i)
  {

    if (j==4)
   SDL_BlitSurface(volume100.img,NULL,ecran,&(volume100.pos)) ;  
   else if (j==3)
   SDL_BlitSurface(volume75.img,NULL,ecran,&(volume75.pos)) ;  
   else if (j==2) 
   SDL_BlitSurface(volume50.img,NULL,ecran,&(volume50.pos)) ;  
    else if(j==1)
   SDL_BlitSurface(volume25.img,NULL,ecran,&(volume25.pos)) ;  
    else if (j==0)
   SDL_BlitSurface(volume0.img,NULL,ecran,&(volume0.pos)) ;  

  }

                        SDL_Flip(ecran);
                    }
                    x=4;
                    break ;
                
                }
            }
            break;

        }



                  if (fr<=179)   
                   { update_transition(ecran ,tab,&fr) ;
                     if (actuel - prec > 60)
                         {
                           update_transition(ecran ,tab,&fr) ;
                           prec = actuel;

                         }
                      else 
                         {
                           SDL_Delay(60 - (actuel - prec));
                         }
                   }

                  else
                  {
        SDL_BlitSurface(imageDeFond, NULL, ecran, &position);

        if(so==1)
            SDL_BlitSurface(solo, NULL, ecran, &position);
        else if(mp==1)
            SDL_BlitSurface(multi, NULL, ecran, &position);
        else if(ex==1)
            SDL_BlitSurface(exit, NULL, ecran, &position);
        else if(se==1)
            SDL_BlitSurface(sett, NULL, ecran, &position);
        else if(cr==1)
            SDL_BlitSurface(cred, NULL, ecran, &position);
                  }
        SDL_Flip(ecran);

    }

    Mix_FreeMusic(music);

    SDL_FreeSurface(imageDeFond);
    SDL_FreeSurface(Menu0);
    SDL_FreeSurface(Menu1);
    SDL_FreeSurface(Menu2);
    SDL_FreeSurface(solo);
    SDL_FreeSurface(multi);
    SDL_FreeSurface(sett);
    SDL_FreeSurface(cred);
    SDL_FreeSurface(exit);
    

    Mix_CloseAudio();
    SDL_Quit();

    return EXIT_SUCCESS;


}
