#ifndef TANK_GAME_H
#define TANK_GAME_H

#include "config.h"
#include "bullet.h"
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

class Game
{
private:
    std::vector<Bullet> bullets;
};

#endif
