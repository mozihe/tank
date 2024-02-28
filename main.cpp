#include <SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <ctime>
#include "config.h"
#include "game.h"

int main()
{
    srand(time(NULL));
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Tank", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    char title[100];
    int scorer = 0;
    int scoreb = 0;
    SDL_Event event;
    bool running = true;
    Game game;
    while (running)
    {
        Uint32 frameStart = SDL_GetTicks();
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = false;
            else if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_UP:
                    game.getPlayer2()->move(UP, game.getPlayer1()->point.x, game.getPlayer1()->point.y);
                    break;
                case SDLK_DOWN:
                    game.getPlayer2()->move(DOWN, game.getPlayer1()->point.x, game.getPlayer1()->point.y);
                    break;
                case SDLK_LEFT:
                    game.getPlayer2()->move(LEFT, game.getPlayer1()->point.x, game.getPlayer1()->point.y);
                    break;
                case SDLK_RIGHT:
                    game.getPlayer2()->move(RIGHT, game.getPlayer1()->point.x, game.getPlayer1()->point.y);
                    break;
                case SDLK_w:
                    game.getPlayer1()->move(UP, game.getPlayer2()->point.x, game.getPlayer2()->point.y);
                    break;
                case SDLK_s:
                    game.getPlayer1()->move(DOWN, game.getPlayer2()->point.x, game.getPlayer2()->point.y);
                    break;
                case SDLK_a:
                    game.getPlayer1()->move(LEFT, game.getPlayer2()->point.x, game.getPlayer2()->point.y);
                    break;
                case SDLK_d:
                    game.getPlayer1()->move(RIGHT, game.getPlayer2()->point.x, game.getPlayer2()->point.y);
                    break;
                case SDLK_SPACE:
                    game.shoot(RED, game.getPlayer2()->point.x + 25, game.getPlayer2()->point.y + 25, game.getPlayer2()->direction, game.getPlayer2()->level);
                    break;
                case SDLK_q:
                    game.shoot(BLUE, game.getPlayer1()->point.x + 25, game.getPlayer1()->point.y + 25, game.getPlayer1()->direction, game.getPlayer1()->level);
                    break;
                }
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        if (game.getWinner() == 0)
        {
            game.update();
            game.draw(renderer);
        }
        else
        {
            if (game.getWinner() == 1) {
                scoreb++;
                filledCircleRGBA(renderer, 775, 425, 100, 0, 0, 255, 255);
                SDL_SetWindowTitle(window,"点击T键继续游戏");
                SDL_RenderPresent(renderer);
                while( SDL_WaitEvent(&event))
                {

                    if(event.type == SDL_QUIT)
                    {
                        return 0;
                    }
                    if(event.key.keysym.sym == SDLK_t)
                    {
                        game.regame();
                        goto lj35;
                    }
                }
                lj35:
                sprintf(title, "tank      BLUE: %d   RED: %d", scoreb,scorer);
                SDL_SetWindowTitle(window, title);
                continue;
            }
            else {
                scorer++;
                filledCircleRGBA(renderer, 775, 425, 100, 255, 0, 0, 255);
                SDL_SetWindowTitle(window,"点击T键继续游戏");
                SDL_RenderPresent(renderer);
                while(SDL_WaitEvent(&event))
                {

                    if(event.type == SDL_QUIT)
                    {
                        return 0;
                    }
                    if(event.key.keysym.sym == SDLK_t)
                    {
                        game.regame();
                        goto laji35;
                    }
                }
                laji35:
                sprintf(title, "tank      BLUE: %d   RED: %d", scoreb,scorer);
                SDL_SetWindowTitle(window, title);

                continue;
            }
        }

        SDL_RenderPresent(renderer);
        Uint32 frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);

    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}