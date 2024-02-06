#include <SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "config.h"
#include "bullet.h"

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Tank", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    SDL_Event event;
    bool running = true;
    Bullet bullet(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, UP, RED);
    while (running)
    {
        Uint32 frameStart = SDL_GetTicks();
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = false;
            else if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_UP:
                    bullet = Bullet(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, UP, RED);
                    break;
                case SDLK_DOWN:
                    bullet = Bullet(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, DOWN, RED);
                    break;
                case SDLK_LEFT:
                    bullet = Bullet(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, LEFT, RED);
                    break;
                case SDLK_RIGHT:
                    bullet = Bullet(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, RIGHT, RED);
                    break;
                case SDLK_w:
                    bullet = Bullet(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, UP, BLUE);
                    break;
                case SDLK_s:
                    bullet = Bullet(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, DOWN, BLUE);
                    break;
                case SDLK_a:
                    bullet = Bullet(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, LEFT, BLUE);
                    break;
                case SDLK_d:
                    bullet = Bullet(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, RIGHT, BLUE);
                    break;
                case SDLK_KP_0:
                    running = false;
                    break;
                case SDLK_f:
                    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
                }
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        bullet.move();
        bullet.draw(renderer);
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