// use to compil : gcc -Wall -Wextra -Werror -lSDL2 -lSDL2_image *.c

//SDL_RenderPresent(renderer) -> affiche le rendu;
//SDL_RenderClear(renderer) -> efface le rendu;

#include "zeltat.h"

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

int main(void)
{
    t_init      SDL;
    SDL_Event   event;
    int         enter;
    int         quit = 1;

    if (!init_SDL(&SDL))
    {
        printf("Error: Failed to init SDL.\n");
        return (0);
    }

    SDL.menu_play = IMG_Load(PATH_MENU_PLAY);
    SDL.menu_quit = IMG_Load(PATH_MENU_QUIT);
    SDL.texture_menu_play = SDL_CreateTextureFromSurface(SDL.renderer, SDL.menu_play);
    SDL_FreeSurface(SDL.menu_play);
    SDL.texture_menu_quit = SDL_CreateTextureFromSurface(SDL.renderer, SDL.menu_quit);
    SDL_FreeSurface(SDL.menu_quit);

    SDL_RenderCopy(SDL.renderer, SDL.texture_menu_play, 0, 0);
    while (quit)
    {
        SDL_RenderPresent(SDL.renderer);
        while (SDL_WaitEvent(&event))
        {
            if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
            {
                quit = 0;
                break ;
            }
            if (event.key.keysym.scancode == 40 && enter == 1)
            {
                quit = 0;
                break ;
            }
            if (event.key.keysym.scancode == SDL_SCANCODE_UP)
            {
                menu_play(&SDL);
                enter = 0;
                break ;
            }
            if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
            {
                menu_quit(&SDL);
                enter = 1;
                break ;
            }
        }
    }

    SDL_DestroyRenderer(SDL.renderer);
    SDL_DestroyWindow(SDL.win);
    SDL_Quit();
    return (0);
}
