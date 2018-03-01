#ifndef ROBERT_H
#define ROBERT_H
#include "entities.h"
#include "math.h"
#include <stdlib.h>

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


void cautare_cursa_optima(car* masina, ride* rides, info informatii, unsigned int step)
{
    unsigned int timp_drum, timp_cursa, timp_total, DistantaOptima = 2000000;
    int i, IdOptim;
    for(i = 0; i < informatii.numberOfRides; i++)
    {
        if(rides[i].isAvailable)
        {
            timp_drum = (unsigned int)floor((double)(rides[i].startX - masina->positionX + rides[i].startY - masina->positionY));
            timp_cursa = (unsigned int)floor((double)(rides[i].startX - rides[i].finishX + rides[i].startY - rides[i].finishY));
            timp_total=timp_drum + timp_cursa;
            if(timp_total + step <= rides[i].latestFinish && timp_total<=DistantaOptima)
            {
                DistantaOptima=timp_total;
                IdOptim=rides[i].id;
            }
        }
    }
    rides[IdOptim].isAvailable=0;
    masina->isAvailable += timp_total;
    masina->positionX = rides[IdOptim].finishX;
    masina->positionY = rides[IdOptim].finishY;
    masina->ridesDone++;
    realloc(masina->rides, ++masina->ridesDone);
    masina->rides[masina->ridesDone - 1] = rides[IdOptim];
}

void terminare_cursa(car masina)
{
    masina.isAvailable--;
}
#endif // ROBERT_H_INCLUDED
