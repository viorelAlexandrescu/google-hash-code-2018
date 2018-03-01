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
    unsigned int curent_step = 0; // nr actual de step
//    while(curent_step<=)
//    {
        
//    }
//
    return 0;
}
