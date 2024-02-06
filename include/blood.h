#ifndef TANK_BLOOD_H
#define TANK_BLOOD_H
#include <SDL.h>
class blood
{
public:
    blood();
    SDL_Point point;
    void blood_up();
    void draw(SDL_Renderer *renderer);
    int mytime;
};
#endif //TANK_BLOOD_H
