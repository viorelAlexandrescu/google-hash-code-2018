#include <stdio.h>
#include <stdlib.h>
#include "entities.h"
#include "robert.h"
#include "read.h"

int main()
{
    const char *inputPath = "b_should_be_easy.in";
    initInputFile(inputPath);
    info problemDetails = readDetails();
    ride* rides = readRides();
    car masini[problemDetails.numberOfCars];
    int i;
    for(i = 0; i < problemDetails.numberOfCars; i++)
    {
        masini[i].id=i+1;
        masini[i].positionX=0;
        masini[i].positionY=0;
        masini[i].ridesDone=0;
        masini[i].isAvailable=0;
    }
    unsigned int curent_step = 0;

    while(curent_step<=problemDetails.numberOfSteps)
    {
        verificare_curse_valabile(rides,problemDetails.numberOfRides);
        for(i=0;i<problemDetails.numberOfCars;i++)
        {
            if(verificare_masina_valabila(masini[i]))
            {
                cautare_cursa_optima(&masini[i], rides, problemDetails, curent_step);
            }
            terminare_cursa(masini[i]);
        }
    }
    printRides("output.out", masini, problemDetails.numberOfCars);
    return 0;
}
