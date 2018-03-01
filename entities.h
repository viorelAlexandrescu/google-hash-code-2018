#ifndef entities
#define entities

typedef struct {
    unsigned int positionX;
    unsigned int positionY;

    char isAvailable;
    step* steps;
} car;

typedef struct {
    unsigned int startX;
    unsigned int startY;

    unsigned int finishX;
    unsigned int finishY;

    unsigned int earliestStart;
    unsigned int latestFinish;

    char isAvailable;
} ride;

typedef struct {
    unsigned int nextStepX;
    unsigned int nextSteptY;
} step;

#endif
