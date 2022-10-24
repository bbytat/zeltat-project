# include "zeltat.h"

int menu(t_init *SDL)
{
    SDL_bool menu = SDL_TRUE;
    SDL_Event       event;
    int             enter = 0;

    SDL_RenderCopy(SDL->renderer, SDL->texture_menu, 0, 0);
    while (menu)
    {
        SDL_RenderPresent(SDL->renderer);
        SDL_WaitEvent(&event);
        switch(event.key.keysym.scancode)
        {
            case 40:
                if (enter == 0 || enter == 1)
                    menu = SDL_FALSE;
                break;
            case SDL_SCANCODE_ESCAPE:
                menu = SDL_FALSE;
                break;
            case SDL_SCANCODE_UP:
                SDL_RenderClear(SDL->renderer);
                SDL_RenderCopy(SDL->renderer, SDL->texture_menu_play, 0, 0);
                enter = 1;
                break;
            case SDL_SCANCODE_DOWN:
                SDL_RenderClear(SDL->renderer);
                SDL_RenderCopy(SDL->renderer, SDL->texture_menu_quit, 0, 0);
                enter = 0;
                break;
            default:
                continue;
        }
    }
    return (enter);
}

int loadImage(t_init *SDL)
{
    SDL->image = IMG_Load(PATH_MENU);
    SDL->texture_menu = SDL_CreateTextureFromSurface(SDL->renderer, SDL->image);
    SDL_FreeSurface(SDL->image);
    if (SDL->texture_menu == NULL)
     return(1);

    SDL->image = IMG_Load(PATH_MENU_PLAY);
    SDL->texture_menu_play = SDL_CreateTextureFromSurface(SDL->renderer, SDL->image);
    SDL_FreeSurface(SDL->image);
    if (SDL->texture_menu_play == NULL)
     return(1);

    SDL->image = IMG_Load(PATH_MENU_QUIT);
    SDL->texture_menu_quit = SDL_CreateTextureFromSurface(SDL->renderer, SDL->image);
    SDL_FreeSurface(SDL->image);
    if (SDL->texture_menu_quit == NULL)
     return(1);

     return(1);
}

void game(t_init *SDL)
{
    if (!loadImage(SDL))
     {
        printf("Error: Failed to load image.\n");
        return ;
    }
    if (!menu(SDL))
        return ;
}