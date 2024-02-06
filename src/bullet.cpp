#include "../include/bullet.h"

Bullet::Bullet(int x, int y, Direction direction, Team team)
{
    location.x = x;
    location.y = y;
    this->direction = direction;
    this->team = team;
    speed = 4;
}

void Bullet::draw(SDL_Renderer* renderer)
{
    if (team == RED)
        filledCircleRGBA(renderer, location.x, location.y, 5, 255, 0, 0, 255);
    else
        filledCircleRGBA(renderer, location.x, location.y, 5, 0, 0, 255, 255);
}

void Bullet::move()
{
    switch (direction)
    {
    case UP:
        location.y -= speed;
        break;
    case DOWN:
        location.y += speed;
        break;
    case LEFT:
        location.x -= speed;
        break;
    case RIGHT:
        location.x += speed;
        break;
    }
}

bool Bullet::isOutOfBounds()
{
    if (location.x < 0 || location.x > SCREEN_WIDTH || location.y < 0 || location.y > SCREEN_HEIGHT)
        return true;
    return false;
}