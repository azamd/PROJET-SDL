/**
* @file level1.c
* @brief Level 1 of the game.
* @author CyberPunkTeam
* @version 0.2 Alpha Build
* @date Apr 23, 2019
*/
#include "fonction.h"
#include "enigme.h"

void savee(ennemis ennemi,perso perso,int page1,int page2,vie vie,int saut,SDL_Rect camera)
{
FILE *f;
f=fopen("save.bin","wb");
saves saves;
saves.ennemi=ennemi;
saves.camera=camera;
saves.perso=perso;
saves.vie=vie;
saves.saut=saut;
saves.level=1;
fwrite(&saves,sizeof(saves),1,f);
fclose(f);
}
void load(int lvl,ennemis *ennemi,perso *perso,int page1,int page2,vie *vie,int *saut,SDL_Rect *camera,int *continuer,int *save)
{
if (lvl)
{
FILE *f;
f=fopen("save.bin","rb");
saves saves;
fread(&saves,sizeof(saves),1,f);
fclose(f);
ennemi->position.x=saves.ennemi.position.x;
ennemi->position.y=saves.ennemi.position.y;
*camera=saves.camera;
perso->position.x=saves.perso.position.x;
perso->position.y=saves.perso.position.y;
vie->nb=saves.vie.nb;
*saut=saves.saut;
if(saves.level==2||saves.level==3)
{
*continuer=0;
*save=2;
}
}
}

void level1(int *save,int lvl)
{

perso perso ;
vie vie;
map map ;
escalier escalier;
ennemis ennemi ;
enigme  enig;
int ennmouv,w=10;
int prevd,prevq;
int t1=0,t2=0;
int saut=1;
int mvmspeed = 30;
int speed = 50;
SDL_Surface *ecran = NULL,*image1=NULL;

srand(time(NULL)) ;

int d=0,q=0,z=0,s=0,h=0,e=0,jump=0,x=0,y=1;
int continuer = 1,sol,r,alea,run=1,running=1;
int page1=1,page2=1;
char image[30]="";
int run1 =1,firsttime=0  ;
SDL_Event event;
ecran = SDL_SetVideoMode(1000, 560, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
SDL_Rect camera = { 0, 0, ecran->w, ecran->h };
camera.x=0;
camera.y=0;
initialiserfond(&map);
initialiserescalier(&escalier);
initialiserperso(&perso);
 ///init_enigme(&enig);
initialiserennemi(&ennemi);
int running1 =1 ;


initialiservie(&vie) ;
SDL_ShowCursor(SDL_DISABLE);
//SDL_LockSurface;
load(lvl,&ennemi,&perso,page1,page2,&vie,&saut,&camera,&continuer,save);
while (continuer)
{

SDL_PollEvent(&event);
switch(event.type)
    {
        case SDL_QUIT:
	savee(ennemi,perso,page1,page2,vie,saut,camera);
            continuer = 0;
	
  		break;

	case SDL_KEYDOWN:

            switch (event.key.keysym.sym)
            {
 		case SDLK_ESCAPE:
		menuingame(&continuer,ennemi,perso,page1,page2,vie,saut,camera,ecran);
		    
			break;
					
		case SDLK_q :
		q=1;	
                    	break ;

		case SDLK_d :
		d=1; 
			break ;

		case SDLK_z :
		z=1;	
                    	break ;

		case SDLK_s :
		s=1; 
			break ;

		case SDLK_e :
		e=1; 
			break ;
                case SDLK_h :
                h=1;
                break;

		case SDLK_AMPERSAND ://1
		t1=1; 
			break ;

		case SDLK_QUOTEDBL : //3
		t2=1; 
			break ;
		
		case SDLK_SPACE :
		jump=1; 
			break ;
	    }
		break;

	case SDL_KEYUP:

            switch (event.key.keysym.sym)
            {
 		case SDLK_ESCAPE:
		    //continuer=0 ;
			break ;

		case SDLK_q :
		q=0;	
                    	break ;

		case SDLK_d :
		d=0; 
			break ;

		case SDLK_z :
		z=0;	
                    	break ;

		case SDLK_s :
		s=0; 
			break ;

		case SDLK_e :
		e=0; 
			break ;
                case SDLK_h :
                h=0;
                break;
		case SDLK_AMPERSAND ://1
		t1=0; 
			break ;

		case SDLK_QUOTEDBL : //3
		t2=0; 
			break ;
		
		case SDLK_SPACE :
		jump=0; 
			break ;
	    }
		break;
    }

x = mouv(d,q,z,s,x,perso,escalier,camera);

SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
camera = scrolling(d,q,z,s,h,camera,perso,escalier,speed);
camera = collision(camera,perso);
printf("%d\n",h);
perso=mouvement(perso,camera,h,d,q,z,s,escalier,prevd,prevq,&saut,jump,speed);


 /*if ( perso.position.x>=500 && firsttime==0) {  
     firsttime=1 ;
generate_afficher ( ecran  , image ,&enig,&alea) ;
        run1 =1  ;
      while(run1)
{
     do{
        r=resolution (&running1,&run1);
			}while((r>3 || r<1) && running1!=0) ;
      afficher_resultat (ecran,sol,r,&enig) ;
}

}*/
y = splitennemi(y);
collisionennemi(&perso,&ennemi,&camera,&vie);

afficherfond(map,&camera,ecran);
afficherperso(perso,ecran,x);
affichervie(&vie,perso,ecran);
ennemi=mouvennemi(ennemi,perso,d,q,camera,ecran,&ennmouv,&w,&y,mvmspeed);
afficherennemi(ennemi,ecran,y);
prevd = d;
prevq = q;
SDL_Flip(ecran);

SDL_Delay(80);
}
freesurfacemap(&map,&escalier);
freefurfaceperso(&perso);
freesurfaceennemi(&ennemi);
freesurfacevie(&vie);

}
