#ifndef TANK_SHIELD_H
#define TANK_SHIELD_H
#include <SDL.h>
class shield
{
public:
    shield();
    SDL_Point point;
    void shield_up();
    void draw(SDL_Renderer *renderer);
    int mytime;
};
#endif //TANK_SHIELD_H
