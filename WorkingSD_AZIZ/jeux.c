#include "fonction.h"

void jeux(int lvl)
{
    int save=1;

    if(lvl == 1)
        level1(&save,1);
    else
        level1(&save,0);
}
