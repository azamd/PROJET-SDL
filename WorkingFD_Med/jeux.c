#include "fonction.h"

void jeux(int lvl)
{
/**
* @brief Enable/Disable Save Mode.
* @author CyberPunkTeam
* @param lvl Select level number (1, 2 or 3)
* @param save 1 = ON / 0 = OFF
* @return Nothing
*/
    int save=1;

    if(lvl == 1)
        level1(&save,1);
    else
        level1(&save,0);
}
