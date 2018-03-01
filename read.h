#include "entities.h"
#include <stdio.h>

unsigned int numberOfRides;
FILE* input;

void initInputFile(const char* filePath)
{
    input = fopen(filePath, "r");
}

info readDetails(const char *filePath)
{
    info problemDetails;
    fscanf(input, "%u%u%u%u%u%u", &problemDetails.numberOfRows, &problemDetails.numberOfColumns, &problemDetails.numberOfCars, &problemDetails.numberOfRides, &problemDetails.bonus, &problemDetails.numberOfSteps);
    numberOfRides = problemDetails.numberOfRides;
    return problemDetails;
}

ride* readRides(const char *filePath)
{
    ride curse[numberOfRides];

    int i;
    for(i = 0; i < numberOfRides; i++)
    {
        fscanf(input, "%u %u %u %u %u %u" , &curse[i].startX, &curse[i].startY, &curse[i].finishX, &curse[i].finishY, &curse[i].earliestStart, &curse[i].latestFinish);
    }
    return curse;
}

void printRides(const char *filePath, car* cars, unsigned int numberOfCars)
{
    FILE* output = fopen(filePath, "w");
    int i, j;
    for(i = 0; i < numberOfCars; i++)
    {
        fprintf(output, "%u ", cars[i].id);
        for(j = 0; j < cars[i].ridesDone; j++)
        {
            fprintf(output, "%u ",cars[i].rides[j].id);
        }
        fprintf(output, " \n");
    }
    fclose(output);
}
