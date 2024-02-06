#include "game.h"

Game::Game()
{
    winner = 0;
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
            player1.HP -= 10;
            bullets.erase(bullets.begin() + i);
        }
        if (bullet.getPoint().x > player2.point.x && bullet.getPoint().x < player2.point.x + 50 && bullet.getPoint().y > player2.point.y && bullet.getPoint().y < player2.point.y + 50 && bullet.getTeam() == BLUE)
        {
            player2.HP -= 10;
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

void Game::shoot(Team team, int x, int y, Direction direction)
{
    bullets.emplace_back(x, y, direction, team);
}