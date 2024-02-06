#ifndef TANK_PROGRESS_H
#define TANK_PROGRESS_H
#include <SDL.h>
class progress
{
public:
    progress();
    int level;
    SDL_Point point;
    void level_up();
    void draw(SDL_Renderer *renderer);
};
#endif //TANK_PROGRESS_H
