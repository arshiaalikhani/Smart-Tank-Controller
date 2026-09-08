#include <iostream>
#include "tank.h"

tank::tank()
{
    level = 50;
}
void tank::increaseLevel(int amount)
{
    level += amount;
    if(level > 100)
        level = 100;
}
void tank::decreaseLevel(int amount)
{
    level -= amount;
    if(level > 0)
        level = 0;
}
int tank::getLevel()
{
    return level;
}
