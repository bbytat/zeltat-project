#include <SDL2/SDL.h>
#include <stdio.h>

int main(void)
{
    // init SLD
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Error initialisation SDL\n");
        return (0);
    }
    else
        printf("SDL initalised successfull\n");

    // init window SDL
    SDL_Window *window = NULL;
    SDL_Renderer *renderer;
    window = SDL_CreateWindow("Zeltat", 0,0, 640, 480, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (window != NULL)
    {
        SDL_Delay(60000);
        SDL_DestroyWindow(window);
    }
    else
        printf("error creation window\n");

// loading main img
SDL_Surface *image = NULL;

}