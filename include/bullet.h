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
    int level;

public:
    Bullet(int x, int y, Direction direction, Team team, int level);
    void draw(SDL_Renderer* renderer);
    void move();
    bool isOutOfBounds();
    SDL_Point getPoint();
    Team getTeam();
    int getLevel();
};

#endif
