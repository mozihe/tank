#include "game.h"

Game::Game()
{
    winner = 0;
}

void Game::regame()
{
    winner = 0;
    player1.HP = 100;
    player2.HP = 100;
    player1.shield = 0;
    player2.shield = 0;
    player1.point.x = 0;
    player1.point.y = 400;
    player1.direction = RIGHT;
    player2.point.x = 1550;
    player2.point.y = 400;
    player2.direction = LEFT;
}

void Game::draw(SDL_Renderer *renderer)
{
    SDL_Rect rectRed = {player2.point.x, player2.point.y, 50, 50};
    SDL_Rect rectBlue = {player1.point.x, player1.point.y, 50, 50};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rectRed);
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &rectBlue);
    if (!bullets.empty())
    {
        for (auto &bullet : bullets)
        {
            bullet.draw(renderer);
        }
    }
    SDL_Rect rectRedHP = {player2.point.x, player2.point.y - 10, player2.HP / 2, 5};
    SDL_Rect rectBlueHP = {player1.point.x, player1.point.y - 10, player1.HP / 2, 5};
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &rectRedHP);
    SDL_RenderFillRect(renderer, &rectBlueHP);
    pro.draw(renderer);
    blo.draw(renderer);
    shi.draw(renderer);
    if (player1.shield > 0)
    {
        filledCircleRGBA(renderer, player1.point.x + 25, player1.point.y + 25, 50, 100, 150, 255, player1.shield);
    }
    if (player2.shield > 0)
    {
        filledCircleRGBA(renderer, player2.point.x + 25, player2.point.y + 25, 50, 100, 150, 255, player2.shield);
    }
}

void Game::update()
{
    if (!bullets.empty())
    {
        for (auto &bullet : bullets)
        {
            bullet.move();
        }
    }
    checkCollision();
    pro.level_up();
    blo.blood_up();
    shi.shield_up();
    player1.eat(pro.point.x, pro.point.y);
    player2.eat(pro.point.x, pro.point.y);
    player1.eat_blood(blo.point.x, blo.point.y);
    player2.eat_blood(blo.point.x, blo.point.y);
    player1.eat_shield(shi.point.x, shi.point.y);
    player2.eat_shield(shi.point.x, shi.point.y);
    checkWinner();
}

void Game::checkCollision()
{
    for (int i = bullets.size() - 1; i >= 0; --i)
    {
        auto& bullet = bullets[i];
        if (bullet.isOutOfBounds())
        {
            bullets.erase(bullets.begin() + i);
            continue;
        }
        if (bullet.getPoint().x > player1.point.x && bullet.getPoint().x < player1.point.x + 50 && bullet.getPoint().y > player1.point.y && bullet.getPoint().y < player1.point.y + 50 && bullet.getTeam() == RED)
        {
            int Harm = 10;
            switch (bullet.getLevel())
            {
                case 1:
                    Harm = 15;
                    break;
                case 2:
                    Harm = 20;
                    break;
                case 3:
                    Harm = 25;
                    break;
            }
            if (player1.shield > 0)
            {
                player1.shield -= Harm;
                if (player1.shield < 0)
                    player1.shield = 0;
            }
            else
               player1.HP -= Harm;
            bullets.erase(bullets.begin() + i);
        }
        if (bullet.getPoint().x > player2.point.x && bullet.getPoint().x < player2.point.x + 50 && bullet.getPoint().y > player2.point.y && bullet.getPoint().y < player2.point.y + 50 && bullet.getTeam() == BLUE)
        {
            int Harm = 10;
            switch (bullet.getLevel())
            {
                case 1:
                    Harm = 15;
                    break;
                case 2:
                    Harm = 20;
                    break;
                case 3:
                    Harm = 25;
                    break;
            }
            if (player2.shield > 0)
            {
                player2.shield -= Harm;
                if (player2.shield < 0)
                    player2.shield = 0;
            }
            else
                player2.HP -= Harm;
            bullets.erase(bullets.begin() + i);
        }
    }
}

void Game::checkWinner()
{
    if (player1.HP <= 0)
    {
        winner = 2;
    }
    if (player2.HP <= 0)
    {
        winner = 1;
    }
}

tank* Game::getPlayer1()
{
    return &player1;
}

tank* Game::getPlayer2()
{
    return &player2;
}

std::vector<Bullet> Game::getBullets()
{
    return bullets;
}

int Game::getWinner()
{
    return winner;
}

void Game::shoot(Team team, int x, int y, Direction direction, int level)
{
    bullets.emplace_back(x, y, direction, team, level);
}