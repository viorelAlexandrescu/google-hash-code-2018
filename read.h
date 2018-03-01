#include "entities.h"w
unsigned int numberOfRides;
info readin(const char *filePath, int &rides;)
{
    info problemDetails;
    scanf(filePath, %u%u%u%u%u%u, &problemDetails.numberOfRows, &problemDetails.numberOfColumns, &problemDetails.numberOfCars, &problemDetails.numberOfRides, &problemDetails.bonus, &problemDetails.numberOfSteps)
    numberOfRides = problemDetails.numberOfRides;
    return problemDetails;
}

