#ifndef TANK_TANKS_H
#define TANK_TANKS_H

#include <SDL.h>
#include "config.h"

class tank
{
public:
    tank(Team color);
    int HP;
    int level;
    int shield;
    Direction direction;
    Team color;
    SDL_Point point;
    void move(Direction myDirection, int enemyX, int enemyY);
    void eat(int &x, int &y);
    void eat_blood(int &x, int &y);
    void eat_shield(int &x, int &y);
};
#endif //TANK_TANKS_H
