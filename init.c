#include "zeltat.h"

int init_SDL(t_init *SDL)
{

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        return (0);
    SDL->win = SDL_CreateWindow("Zeltat", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!SDL->win)
        return (0);
    SDL->renderer = SDL_CreateRenderer(SDL->win, -1, SDL_RENDERER_ACCELERATED);
    if (!SDL->renderer)
        return (0);
    return (1);
}
    void    menu_play(t_init *SDL)
{
    SDL_RenderClear(SDL->renderer);
    SDL_RenderCopy(SDL->renderer, SDL->texture_menu_play, 0, 0);
}

void    menu_quit(t_init *SDL)
{
    SDL_RenderClear(SDL->renderer);
    SDL_RenderCopy(SDL->renderer, SDL->texture_menu_quit, 0, 0);
}