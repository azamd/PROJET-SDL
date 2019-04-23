#include "fonction.h"

SDL_Rect scrolling(int d,int q,int z,int s,int h,SDL_Rect camera,perso perso,escalier escalier,int speed)
{
int C;
C=collisionescalier(perso,escalier,camera);
if((C==0||C==1)&&(perso.position.y==435||perso.position.y==410||perso.position.y==385||perso.position.y==360||perso.position.y==255||perso.position.y==230||perso.position.y==205||perso.position.y==180))
{
if(d==1&& h==1 && perso.position.x>=500)
{
camera.x=camera.x+speed;
}
else if(d==1 && perso.position.x>=500)
{
camera.x=camera.x+20;
}
if(q==1&& h==1 && perso.position.x<=500)
{
camera.x=camera.x-speed;
}
else if(q==1&& perso.position.x<=500)
{
camera.x=camera.x-20;
}
}
if(C==1&&(perso.position.y!=435||perso.position.y!=255))
{
if(d==1&&perso.position.x==500)
{
camera.x=camera.x+20;
}
if(q==1&&perso.position.x==500)
{
camera.x=camera.x-20;
}
C=collisionescalier(perso,escalier,camera);
if(C==0)
{
if(d==1)
{
camera.x=camera.x-20;
}
if(q==1)
{
camera.x=camera.x+20;
}
}
}
return camera ;
}

/*void scrolling2(int d,int q,perso perso,SDL_Rect *camera)
{
if(d==1&&perso.position.x>=500)
{
camera->x=camera->x+20;
}
if(q==1&&perso.position.x<=500)
{
camera->x=camera->x-20;
}

if(camera->x<0)
{
camera->x=0;
}
if(camera->x>6478)
{
camera->x=6478;
}
}
*/
