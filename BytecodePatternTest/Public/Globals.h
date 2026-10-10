#pragma once
#include "Warrior.h"

constexpr int MAX_NUM_WARRIORS = 10;
// extern int numberOfWarriors;

void setNumberOfWarriors(int number);
int getNumberOfWarriors();

extern Warrior* warriors[MAX_NUM_WARRIORS];
