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
    unsigned int curent_step = 0;
    int i;
    while(curent_step<=problemDetails.numberOfSteps)
    {
        verificare_curse_valabile(rides,problemDetails.numberOfRides);
        for(i=0;i<problemDetails.numberOfCars;i++)
        {
            if(verificare_masina_valabila(masini[i]))
            {
                cautare_cursa_optima(masini[i],rides,problemDetails,curent_step);
            }
            terminare_cursa(masini[i]);
        }
    }
    printRides("output.out", masini, problemDetails.numberOfCars);
    return 0;
}
