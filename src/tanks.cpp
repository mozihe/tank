#include "tanks.h"

void tank::move(Direction myDirection, int enemyX, int enemyY)
{
    if(myDirection == UP && point.y > 0 && (point.x != enemyX || point.y != enemyY + 50))
    {
        point.y -= 50;
    }
    else if(myDirection == DOWN && point.y < 850 && (point.x != enemyX || point.y != enemyY - 50))
    {
        point.y += 50;
    }
    else if(myDirection == RIGHT && point.x < 1550 && (point.x != enemyX - 50 || point.y != enemyY))
    {
        point.x += 50;
    }
    else if(myDirection == LEFT && point.x > 0 && (point.x != enemyX + 50 || point.y != enemyY))
    {
        point.x -= 50;
    }
    this->direction = myDirection;
}


tank::tank(Team color)
{
    HP = 100;
    level = 0;
    if(color == BLUE)
    {
      point.x = 0;
      point.y = 400;
      direction = RIGHT;
    }
    if(color == RED)
    {
        point.x = 1550;
        point.y = 400;
        direction = LEFT;
    }
}

void tank::eat(int &x, int &y)
{
    if(point.x == x && point.y == y)
    {
        if (level < 3)
            level++;
        x = -50;
        y = -50;
    }

}