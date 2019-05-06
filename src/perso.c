#include "fonction.h"

void initialiserperso(perso *perso)
{
perso->a=0;
perso->position.x = 100 ;
perso->position.y = 435 ;
perso->fond00 = IMG_Load("../assets/characters/00.png");
perso->fond0 = IMG_Load("../assets/characters/0.png");
perso->fond1 = IMG_Load("../assets/characters/1.png");
perso->fond2 = IMG_Load("../assets/characters/2.png");
perso->fond3 = IMG_Load("../assets/characters/3.png");
perso->fonda = IMG_Load("../assets/characters/a.png");
perso->fondb = IMG_Load("../assets/characters/b.png");
perso->fondc = IMG_Load("../assets/characters/c.png");
}

void initialiserperso2(perso *perso)
{
perso->a=0;
perso->position.x = 0 ;
perso->position.y = 240 ;
perso->fond00 = IMG_Load("../assets/characters/00.png");
perso->fond0 = IMG_Load("../assets/characters/0.png");
perso->fond1 = IMG_Load("../assets/characters/1.png");
perso->fond2 = IMG_Load("../assets/characters/2.png");
perso->fond3 = IMG_Load("../assets/characters/3.png");
perso->fonda = IMG_Load("../assets/characters/a.png");
perso->fondb = IMG_Load("../assets/characters/b.png");
perso->fondc = IMG_Load("../assets/characters/c.png");
}

void initialiserperso3(perso *perso)
{
perso->a=0;
perso->position.x = 0 ;
perso->position.y = 350 ;
perso->fond00 = IMG_Load("../assets/characters/00.png");
perso->fond0 = IMG_Load("../assets/characters/0.png");
perso->fond1 = IMG_Load("../assets/characters/1.png");
perso->fond2 = IMG_Load("../assets/characters/2.png");
perso->fond3 = IMG_Load("../assets/characters/3.png");
perso->fonda = IMG_Load("../assets/characters/a.png");
perso->fondb = IMG_Load("../assets/characters/b.png");
perso->fondc = IMG_Load("../assets/characters/c.png");
}

void freefurfaceperso(perso *perso)
{
SDL_FreeSurface(perso->fond00);
SDL_FreeSurface(perso->fond0);
SDL_FreeSurface(perso->fond1);
SDL_FreeSurface(perso->fond2);
SDL_FreeSurface(perso->fond3);
SDL_FreeSurface(perso->fonda);
SDL_FreeSurface(perso->fondb);
SDL_FreeSurface(perso->fondc);
}

int mouv(int d,int q,int z,int s,int x,perso perso,escalier escalier,SDL_Rect camera)
{
if(d==0&&q==0)
{
if(x>0&&x<5)
{
x=1;
}
if(x>4&&x<9)
{
x=5;
}
}

if(d==1)
{
switch(x)
{
case 0:
x=1;
	break;
case 1:
x=2;
	break;
case 2:
x=3;
	break;
case 3:
x=4;
	break;
case 4:
x=1;
	break;
default:
x=1;
}
}

if(q==1)
{
switch(x)
{
case 0:
x=5;
	break;
case 5:
x=6;
	break;
case 6:
x=7;
	break;
case 7:
x=8;
	break;
case 8:
x=5;
	break;
default:
x=5;
}
}
	
if(z==1||s==1)
{
if(collisionescalier(perso,escalier,camera))
{
if(z==1)
{x=9;}
if(s==1)
{x=0;}
}
}	
return x ;
}

void splitperso2(int d,int q,int *x)
{
if(d==0&&q==0)
{
if(*x>0&&*x<5)
{
*x=1;
}
if(*x>4&&*x<9)
{
*x=5;
}
}

if(d==1)
{
switch(*x)
{
case 0:
*x=1;
	break;
case 1:
*x=2;
	break;
case 2:
*x=3;
	break;
case 3:
*x=4;
	break;
case 4:
*x=1;
	break;
default:
*x=1;
}
}
if(q==1)
{
switch(*x)
{
case 0:
*x=5;
	break;
case 5:
*x=6;
	break;
case 6:
*x=7;
	break;
case 7:
*x=8;
	break;
case 8:
*x=5;
	break;
default:
*x=5;
}
}
}

perso mouvement(perso perso,SDL_Rect camera,int h,int d,int q,int z,int s,escalier escalier,int prevd,int prevq,int *saut,int jump,int speed)
{
int C;
C=collisionescalier(perso,escalier,camera);
if((C==0||C==1)&&(perso.position.y==435||perso.position.y==410||perso.position.y==385||perso.position.y==360||perso.position.y==255||perso.position.y==230||perso.position.y==205||perso.position.y==180))
{
if(camera.x<=0||camera.x>=6460)
{
 if (d==1&&h==1&&perso.position.x<=940)
{
perso.position.x=perso.position.x+speed+perso.a;	
}else if(d==1&&perso.position.x<=940)
{
perso.position.x=perso.position.x+20+perso.a;
if(perso.position.x>=940)
{
perso.position.x=940;
}
}
if(q==1&&perso.position.x>=0)
{
perso.position.x=perso.position.x-20-perso.a;
if(perso.position.x<=0)
{
perso.position.x=0;
}
}
else if (q==1 && h==1)
{
perso.position.x=perso.position.x-speed-perso.a;
}
}
else 
{
perso.position.x = 500 ;
}
}
if(C==1&&(perso.position.y!=435||perso.position.y!=255))
{
if(camera.x<=0||camera.x>=6460)
{
if(d==1&&perso.position.x<925)
{
perso.position.x=perso.position.x+20+perso.a;
}
else if(d==1&& h==1)
{
perso.position.x=perso.position.x+speed+perso.a;	
}
if(q==1&&perso.position.x>0)
{
perso.position.x=perso.position.x-20-perso.a;
}
else if(q==1 && h==1)
{
perso.position.x= perso.position.x-speed-perso.a;	
}
}
C=collisionescalier(perso,escalier,camera);
if(C==0)
{
if(d==1)
{
perso.position.x=perso.position.x-20-perso.a;
}
if(q==1)
{
perso.position.x=perso.position.x+20+perso.a;
}
}
}
C=collisionescalier(perso,escalier,camera);
if(jump==1&&((perso.position.y==435&&C!=1)||perso.position.y==255)||*saut!=1)
{
switch(*saut)
{
case 1:
perso.position.y-=25;
*saut = 2;
	break ;
case 2:
perso.position.y-=25;
*saut = 3 ;
	break ;
case 3:
perso.position.y-=25;
*saut = 4;
	break ;
case 4:
perso.position.y+=25;
*saut = 5;
	break ;
case 5:
perso.position.y+=25;
*saut = 6;
	break ;
case 6:
perso.position.y+=25;
*saut = 1;
	break ;
}
}
C=collisionescalier(perso,escalier,camera);
if(C==1&&*saut==1)
{
if(s==1)
{
perso.position.y=perso.position.y+20;
}
if(z==1)
{
perso.position.y=perso.position.y-20;
}
C=collisionescalier(perso,escalier,camera);
if(C==0)
{
if(s==1)
{
perso.position.y=perso.position.y-20;
}
if(z==1)
{
perso.position.y=perso.position.y+20;
}
}
}
if((prevd==d||prevq==q)&&prevd!=prevq)
{
perso.a=perso.a+1;
}
else
{
perso.a=0;
}
if(perso.a>20)
{
perso.a=20;
}

return perso;
}

void mouvperso2(int d,int q,perso *perso,int jump,int *saut,SDL_Rect camera,map map,int prevd,int prevq,int *continuer,SDL_Surface *ecran,int *save)
{
int x=1;
perso->position.y+=25;	
Uint32 Blanc = SDL_MapRGB(map.fond2->format,255,255,255);
if(camera.x<=0||camera.x>=6478)
{
if(d==1&&perso->position.x<=940)
{
perso->position.x=perso->position.x+20+perso->a;
if(perso->position.x>=940)
{
perso->position.x=940;
}
}
if(q==1&&perso->position.x>=0)
{
perso->position.x=perso->position.x-20-perso->a;
if(perso->position.x<=0)
{
perso->position.x=0;
}
}
}
else 
{
perso->position.x = 500 ;
}

if(jump==1||*saut!=1)
{
switch(*saut)
{
case 1:
perso->position.y-=50;
*saut = 2;
	break ;
case 2:
perso->position.y-=50;
*saut = 3 ;
	break ;
case 3:
perso->position.y-=50;
*saut = 4;
	break ;
case 4:
perso->position.y-=50;
*saut = 5;
	break ;
case 5:
perso->position.y-=50;
*saut = 6;
	break ;
case 6:
*saut = 7;
	break ;
case 7:
*saut = 8;
	break ;
case 8:
*saut = 9;
	break;
case 9:
*saut = 10;
	break ;
case 10:
if(getpixel(map.fond2,camera.x+perso->position.x,perso->position.y+124) == Blanc)
{
*saut = 1;
}
	break ;
}
}

while(getpixel(map.fond2,camera.x+perso->position.x,perso->position.y+124) == Blanc)
{
perso->position.y-=1;
}
if((prevd==d||prevq==q)&&prevd!=prevq)
{
perso->a=perso->a+1;
}
else
{
perso->a=0;
}
if(perso->a>15)
{
perso->a=15;
}
if(camera.x>=6478)
{
while(x!=10)
{
switch(x)
{
case 1:
SDL_BlitSurface(map.ff1,NULL, ecran,&map.position);
x++;
	break;
case 2:
SDL_BlitSurface(map.ff2,NULL, ecran,&map.position);
x++;
	break;
case 3:
SDL_BlitSurface(map.ff3,NULL, ecran,&map.position);
x++;
	break;
case 4:
SDL_BlitSurface(map.ff4,NULL, ecran,&map.position);
x++;
	break;
case 5:
SDL_BlitSurface(map.ff5,NULL, ecran,&map.position);
x++;
	break;
case 6:
SDL_BlitSurface(map.ff6,NULL, ecran,&map.position);
x++;
	break;
case 7:
SDL_BlitSurface(map.ff7,NULL, ecran,&map.position);
x++;
	break;
case 8:
SDL_BlitSurface(map.ff8,NULL, ecran,&map.position);
x++;
	break;
case 9:
SDL_BlitSurface(map.ff9,NULL, ecran,&map.position);
x++;
	break;
case 10:
SDL_BlitSurface(map.ff10,NULL, ecran,&map.position);
x++;
	break;
}
SDL_Flip(ecran);
SDL_Delay(80);
}
*save=3;
*continuer=0;
}
}

void mouvperso3(int d,int q,perso *perso,int jump,int *saut,SDL_Rect camera,map map,int prevd,int prevq,int *continuer,SDL_Surface *ecran)
{
int x=1;
perso->position.y+=25;	
Uint32 Blanc = SDL_MapRGB(map.fond2->format,255,255,255);
if(camera.x<=0||camera.x>=6478)
{
if(d==1&&perso->position.x<=940)
{
perso->position.x=perso->position.x+20+perso->a;
if(perso->position.x>=940)
{
perso->position.x=940;
}
}
if(q==1&&perso->position.x>=0)
{
perso->position.x=perso->position.x-20-perso->a;
if(perso->position.x<=0)
{
perso->position.x=0;
}
}
}
else 
{
perso->position.x = 500 ;
}

if(jump==1||*saut!=1)
{
switch(*saut)
{
case 1:
perso->position.y-=50;
*saut = 2;
	break ;
case 2:
perso->position.y-=50;
*saut = 3 ;
	break ;
case 3:
perso->position.y-=50;
*saut = 4;
	break ;
case 4:
perso->position.y-=50;
*saut = 5;
	break ;
case 5:
perso->position.y-=50;
*saut = 6;
	break ;
case 6:
*saut = 7;
	break ;
case 7:
*saut = 8;
	break ;
case 8:
*saut = 9;
	break;
case 9:
*saut = 10;
	break ;
case 10:
if(getpixel(map.fond2,camera.x+perso->position.x,perso->position.y+124) == Blanc)
{
*saut = 1;
}
	break ;
}
}

while(getpixel(map.fond2,camera.x+perso->position.x,perso->position.y+124) == Blanc)
{
perso->position.y-=1;
}
if((prevd==d||prevq==q)&&prevd!=prevq)
{
perso->a=perso->a+1;
}
else
{
perso->a=0;
}
if(perso->a>15)
{
perso->a=15;
}

if(camera.x>=6478&&perso->position.x>=800)
{
while(x!=10)
{
switch(x)
{
case 1:
x++;
	break;
case 2:
x++;
	break;
case 3:
x++;
	break;
case 4:
x++;
	break;
case 5:
x++;
	break;
case 6:
x++;
	break;
case 7:
x++;
	break;
case 8:
x++;
	break;
case 9:
x++;
	break;
case 10:
x++;
	break;
}
SDL_Flip(ecran);
}
*continuer=0;
}
}

void obstacle2(vie *vie,map map,perso *perso,SDL_Rect *camera)
{
Uint32 Black = SDL_MapRGB(map.fond3->format,0,0,0);
if(getpixel(map.fond3,camera->x+perso->position.x,perso->position.y+124) == Black||getpixel(map.fond3,camera->x+perso->position.x+35,perso->position.y+124) == Black)
{
camera->x=0;
perso->position.x=0;
perso->position.y=240;
vie->nb--;
}
}

void obstacle(vie *vie,map map,perso *perso,SDL_Rect *camera)
{
Uint32 Black = SDL_MapRGB(map.fond2->format,0,0,0);
if(getpixel(map.fond2,camera->x+perso->position.x,perso->position.y+124) == Black||getpixel(map.fond2,camera->x+perso->position.x+35,perso->position.y+124) == Black)
{
camera->x=0;
perso->position.x=0;
perso->position.y=350;
vie->nb--;
}
}

void afficherperso(perso perso,SDL_Surface *ecran,int x)
{
switch(x)
{
case 0:
SDL_BlitSurface(perso.fond0,NULL, ecran,&perso.position);
	break ;
case 1:
SDL_BlitSurface(perso.fond1,NULL, ecran,&perso.position);
	break ;
case 2:
SDL_BlitSurface(perso.fond2,NULL, ecran,&perso.position);
	break ;
case 3:
SDL_BlitSurface(perso.fond1,NULL, ecran,&perso.position);
	break ;
case 4:
SDL_BlitSurface(perso.fond3,NULL, ecran,&perso.position);
	break ;
case 5:
SDL_BlitSurface(perso.fonda,NULL, ecran,&perso.position);
	break ;
case 6:
SDL_BlitSurface(perso.fondb,NULL, ecran,&perso.position);
	break ;
case 7:
SDL_BlitSurface(perso.fonda,NULL, ecran,&perso.position);
	break ;
case 8:
SDL_BlitSurface(perso.fondc,NULL, ecran,&perso.position);
	break ;
case 9:
SDL_BlitSurface(perso.fond00,NULL, ecran,&perso.position);
	break ;
}
}

void initialiservie(vie *vie)
{
vie->nb=3;
vie->position.x = 0 ;
vie->position.y = 0 ;
vie->position2.x = 0 ;
vie->position2.y = 0 ;
vie->fond1 = IMG_Load("../assets/characters/v1.png");
vie->fond2 = IMG_Load("../assets/characters/v2.png");
vie->fond3 = IMG_Load("../assets/characters/v3.png");
vie->fond4 = IMG_Load("../assets/characters/v4.png");
vie->fond5 = IMG_Load("../assets/map/GameOver.png");
}

void freesurfacevie(vie *vie)
{
SDL_FreeSurface(vie->fond1);
SDL_FreeSurface(vie->fond2);
SDL_FreeSurface(vie->fond3);
SDL_FreeSurface(vie->fond4);
SDL_FreeSurface(vie->fond5);
}

void affichervie(vie *vie,perso perso,SDL_Surface *ecran)
{
vie->position.x=perso.position.x-30;
vie->position.y=perso.position.y-40;
if(vie->nb==3)
{
SDL_BlitSurface(vie->fond1,NULL, ecran,&vie->position);

}
if(vie->nb==2)
{
SDL_BlitSurface(vie->fond2,NULL, ecran,&vie->position);
}
if(vie->nb==1)
{
SDL_BlitSurface(vie->fond3,NULL, ecran,&vie->position);
}
if(vie->nb==0)
{
SDL_BlitSurface(vie->fond4,NULL, ecran,&vie->position);
SDL_BlitSurface(vie->fond5,NULL, ecran,&vie->position2);
vie->nb=3;
SDL_Flip(ecran);
sleep(4);
}
}

