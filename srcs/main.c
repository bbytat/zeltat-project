// use to compil : gcc -Wall -Wextra -Werror -lSDL2 -lSDL2_image *.c

//SDL_RenderPresent(renderer) -> affiche le rendu;
//SDL_RenderClear(renderer) -> efface le rendu;

#include "../zeltat.h"

int main()
{
    t_init  SDL;

    if (!init_SDL(&SDL))
    {
        printf("Error: Failed to init SDL.\n");
        return (0);
    }
    game(&SDL);
    SDL_DestroyRenderer(SDL.renderer);
    SDL_DestroyWindow(SDL.win);
    SDL_Quit();

return(0);

}
