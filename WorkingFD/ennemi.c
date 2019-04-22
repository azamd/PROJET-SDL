#include "fonction.h"

void initialiserennemi(ennemis *ennemi)
{
ennemi->position.x = 1001 ;
ennemi->position.y = 240 ;
ennemi->position2.x = 0 ;
ennemi->position2.y = 0 ;
ennemi->fond = IMG_Load("../game/perso/warning.png");
ennemi->fond1 = IMG_Load("../game/perso/x1.png");
ennemi->fond2 = IMG_Load("../game/perso/x2.png");
ennemi->fonda = IMG_Load("../game/perso/xa.png");
ennemi->fondb = IMG_Load("../game/perso/xb.png");
}

void freesurfaceennemi(ennemis *ennemi)
{
SDL_FreeSurface(ennemi->fond);
SDL_FreeSurface(ennemi->fond1);
SDL_FreeSurface(ennemi->fond2);
SDL_FreeSurface(ennemi->fonda);
SDL_FreeSurface(ennemi->fondb);
}
ennemis mouvennemi(ennemis ennemi,perso perso,int d,int q,SDL_Rect camera,SDL_Surface *ecran,int *ennmouv,int *w,int *y,int mvmspeed)
{
int r ;
r = rand();
if((ennemi.position.x<-130||ennemi.position.x>1000)&&(camera.x>0&&camera.x<6460))
{
if(r%1==0)
{
if(ennemi.position.x<-130)
{
ennemi.position.x=-130;
}
if(ennemi.position.x>1000)
{
ennemi.position.x=1000;
}
if(perso.position.y==435||perso.position.y==255)
{
if(perso.position.y==435)
{
ennemi.position.y = 420 ;
}
else
{
ennemi.position.y = 240 ;
}
}
}
}
if((((ennemi.position.x-perso.position.x<300&&ennemi.position.x-perso.position.x>0)||(perso.position.x-ennemi.position.x<300&&perso.position.x-ennemi.position.x>0))&&perso.position.y==255&&ennemi.position.y == 240)||(((ennemi.position.x-perso.position.x<300&&ennemi.position.x-perso.position.x>0)||(perso.position.x-ennemi.position.x<300&&perso.position.x-ennemi.position.x>0))&&perso.position.y==435&&ennemi.position.y == 420))
{

ennemi.position2.x = ennemi.position.x + 50;
ennemi.position2.y = ennemi.position.y - 70;
SDL_BlitSurface(ennemi.fond,NULL, ecran,&ennemi.position2);
if(ennemi.position.x-perso.position.x<300&&ennemi.position.x-perso.position.x>0)
{
if((*y)!=1&&(*y)!=2)
{
(*y)=1;
}
if((d==0&&q==0)||camera.x==0||camera.x==6460)
{
ennemi.position.x=ennemi.position.x-10;
(*w)=10;
return ennemi;
}
if(d==1)
{
ennemi.position.x=ennemi.position.x-15-perso.a;
}
if(q==1)
{
ennemi.position.x=ennemi.position.x-mvmspeed+perso.a;
}
}
if(perso.position.x-ennemi.position.x<300&&perso.position.x-ennemi.position.x>0)
{
if((*y)!=3&&(*y)!=4)
{
(*y)=3;
}
if((d==0&&q==0)||camera.x==0)
{
ennemi.position.x=ennemi.position.x+10;
(*w)=10;
return ennemi;
}
if(d==1)
{
ennemi.position.x=ennemi.position.x+20-perso.a;
}
if(q==1)
{
ennemi.position.x=ennemi.position.x+mvmspeed+perso.a;
}
}
(*w)=10;
return ennemi;
}
r = rand();
if(ennemi.position.x>=-130&&ennemi.position.x<=1000)
{
if(*w<10)
{
if(*ennmouv==1)
{
if((d==0&&q==0)||camera.x==0||camera.x==6460)
{
ennemi.position.x=ennemi.position.x+15;
return ennemi;
}
if(d==1)
{
ennemi.position.x=ennemi.position.x+5-perso.a;
}
if(q==1)
{
ennemi.position.x=ennemi.position.x+20+perso.a;
}
}
if(*ennmouv==2)
{
if((d==0&&q==0)||camera.x==0)
{
ennemi.position.x=ennemi.position.x-15;
return ennemi;
}
if(d==1)
{
ennemi.position.x=ennemi.position.x-20-perso.a;
}
if(q==1)
{
ennemi.position.x=ennemi.position.x-5+perso.a;
}
}
*w=*w+1;
}
if(*w==10)
{
if(r%2==0)
{
*ennmouv=1;
*y=3;
}
if(r%2!=0)
{
*ennmouv=2;
*y=1;
}
*w=0;
}
}
return ennemi;
}

int splitennemi(int y)
{

switch(y)
{
case 1:
y=2;
	break;
case 2:
y=1;
	break;
case 3:
y=4;
	break;
case 4:
y=3;
	break;
}	
return y ;
}



void afficherennemi(ennemis ennemi,SDL_Surface *ecran,int y)
{
switch(y)
{
case 3:
SDL_BlitSurface(ennemi.fond1,NULL, ecran,&ennemi.position);
	break ;
case 4:
SDL_BlitSurface(ennemi.fond2,NULL, ecran,&ennemi.position);
	break ;
case 1:
SDL_BlitSurface(ennemi.fonda,NULL, ecran,&ennemi.position);
	break ;
case 2:
SDL_BlitSurface(ennemi.fondb,NULL, ecran,&ennemi.position);
	break ;
}
}


