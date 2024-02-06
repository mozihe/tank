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
    Direction direction;
    Team color;
    SDL_Point point;
    void move(Direction direction);
};
#endif //TANK_TANKS_H
