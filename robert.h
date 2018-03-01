#ifndef ROBERT_H
#define ROBERT_H
#include "entities.h"
#include "math.h"

unsigned int verificare_masina_valabila(car masina)
{
    if(masina.isAvailable==0)
        return 1;
    else return 0;
}

void verificare_curse_valabile(ride* rides, unsigned int maxRides)
{
    unsigned int timp_cursa, timp_necesar;
    int i;
    for(i = 0; i < maxRides; i++)
    {
        timp_cursa = (unsigned int)floor((double)(rides[i].finishX - rides[i].startX + rides[i].finishY - rides[i].startY));
        timp_necesar = (unsigned int)floor((double)(rides[i].latestFinish-rides[i].earliestStart));
        if(timp_necesar >= timp_cursa)
        {
            rides[i].isAvailable = 0;
        }
    }

}


void cautare_cursa_optima(car masina, ride cursa, info informatii)
{
    unsigned int timp_drum, timp_cursa, timp_total;
    timp_drum = (unsigned int)floor( (double)(ride.startX-masina.positionX+) )
}


#endif // ROBERT_H_INCLUDED
