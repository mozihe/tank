#ifndef TANK_BULLET_H
#define TANK_BULLET_H

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include "config.h"

class Bullet
{
private:
    SDL_Point location;
    int speed;
    Direction direction;
    Team team;
public:
    Bullet(int x, int y, Direction direction, Team team);
    void draw(SDL_Renderer* renderer);
    void move();
    bool isOutOfBounds();
};

#endif
