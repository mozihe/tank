#ifndef TANK_GAME_H
#define TANK_GAME_H

#include "config.h"
#include "bullet.h"
#include "tanks.h"
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

class Game
{
private:
    std::vector<Bullet> bullets;
    tank player1 = tank(BLUE), player2 = tank(RED);
    int winner;

public:
    Game();
    void draw(SDL_Renderer *renderer);
    void update();
    void checkCollision();
    void checkWinner();
    tank *getPlayer1();
    tank *getPlayer2();
    std::vector<Bullet> getBullets();
    int getWinner();
    void shoot(Team team, int x, int y, Direction direction);
};

#endif
