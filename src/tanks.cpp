#include "tanks.h"

void tank::move(Direction direction)
{
    if(direction==UP&&point.y>=0)
    {
        point.y-=50;
    }
    if(direction==DOWN&&point.y<=850)
    {
        point.y+=50;
    }
    if(direction==RIGHT&&point.x<=1550)
    {
        point.x+=50;
    }
    if(direction==UP&&point.x>=0)
    {
        point.x-=50;
    }
    this->direction = direction;
}


tank::tank(Team color)
{
    int HP=100;
    if(color==BLUE)
    {
      point.x=10;
      point.y=425;
      direction=RIGHT;
    }
    if(color==RED)
    {
        point.x=1540;
        point.y=425;
        direction=LEFT;
    }
}
