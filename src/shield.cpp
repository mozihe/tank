#include <shield.h>
#include <cstdlib>
#include <ctime>

void shield::shield_up()
{
    mytime++;
    if(mytime==1000)
    {
        point.x = rand() % 32 * 50;
        point.y = rand() % 18 * 50;
        mytime = 0;
    }
}
shield::shield()
{
    point.x = -50;
    point.y = -50;
    mytime = -2000;
}

void shield::draw(SDL_Renderer *renderer)
{
    SDL_Rect rect = {point.x, point.y, 50, 50};
    SDL_SetRenderDrawColor(renderer, 100, 100, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}