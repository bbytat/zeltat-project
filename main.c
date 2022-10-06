// use to compil : gcc -Wall -Wextra -Werror -lSDL2 -lSDL2_image *.c
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

int main(void)
{
    t_init SDL;

    if (!init_SDL(&SDL))
    {
        printf("Error: Failed to init SDL.\n");
        return (0);
    }
    SDL.path_img = "./img/test.jpg";
    SDL.image = IMG_Load(SDL.path_img);
    SDL.texture = SDL_CreateTextureFromSurface(SDL.renderer, SDL.image);

    while (1)
    {
        SDL_RenderCopy(SDL.renderer, SDL.texture, NULL, NULL);
        SDL_RenderPresent(SDL.renderer);
    }
 
    SDL_Quit();
    return (0);
}
