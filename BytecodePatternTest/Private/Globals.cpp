#include "../Public/Globals.h"

static int numberOfWarriors;

void setNumberOfWarriors(int number)
{
    int n;
    if (number < 0) n = 0;
    else if (number > MAX_NUM_WARRIORS) n = MAX_NUM_WARRIORS;
    else n = number;
    numberOfWarriors = n;
}

int getNumberOfWarriors()
{
    return numberOfWarriors;
}

Warrior* warriors[MAX_NUM_WARRIORS];