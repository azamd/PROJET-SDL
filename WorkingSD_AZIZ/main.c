#include "fonction.h"

int main(int argc, char *argv[])

{
    SDL_Surface *ecran = NULL, *imageDeFond = NULL,*solo = NULL,*multi = NULL,*sett = NULL,*cred = NULL,*exit = NULL,*Volume = NULL;
    SDL_Rect position ;

    Mix_Music *music ;

    position.x = 0 ;
    position.y = 0 ;

    int continuer = 1,continuer0= 1 ;//Game Menu ON/OFF | Options Menu ON/OFF
    int so=0,mp=0,cr=0,se=0,ex=0; //so: solo | mp: multiplayer | cr: credits | se: settings | ex: exit
    int z =128 ;     //z: main volume
    int x = 0 ;    //x: choix

    SDL_Event event;
    Mix_Chunk *MB;  // button
    MB = Mix_LoadWAV("button.wav");// clique de bouton

    ecran = SDL_SetVideoMode(900,425, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("THE ETERNAL STONES ", NULL);

    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    {
        printf("%s",Mix_GetError());
    }

    music = Mix_LoadMUS("musique.mp3");
    Mix_PlayMusic(music,-1);


    SDL_ShowCursor(SDL_ENABLE);

    imageDeFond = IMG_Load("Menu.png");

    solo=IMG_Load("solo.png") ;
    multi=IMG_Load("multi.png") ;
    sett=IMG_Load("sett.png") ;
    cred=IMG_Load("cred.png") ;
    exit=IMG_Load("exit.png") ;



    Volume=IMG_Load("volume.png") ;

    SDL_EnableKeyRepeat(100, 10);
    while (continuer)
    {
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
                case 1 :
                    jeux(1);
                    break ;
                case 2 :
                    

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
                            case SDLK_UP :
                                z = z + 2 ;
                                break ;
                            case SDLK_DOWN :
                                z = z - 2 ;
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

                        SDL_BlitSurface(imageDeFond, NULL, ecran, &position);
                        SDL_BlitSurface(Volume, NULL, ecran, &position);

                        SDL_Flip(ecran);
                    }
                    x=4;
                    break ;
                
                }
            }
            break;

        }






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

        SDL_Flip(ecran);

    }

    Mix_FreeMusic(music);

    SDL_FreeSurface(imageDeFond);

    SDL_FreeSurface(solo);
    SDL_FreeSurface(multi);
    SDL_FreeSurface(sett);
    SDL_FreeSurface(cred);
    SDL_FreeSurface(exit);


    Mix_CloseAudio();
    SDL_Quit();

    return EXIT_SUCCESS;
}

