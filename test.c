#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// use to compil : gcc -Wall -Wextra -Werror -lSDL2 -lSDL2_image test.c

//                     === UPDATE ===                     
// display ok, but need to focus on event right now and also
// refont of the code; secure function, etc..


int main(void)
{
    SDL_Window      *window = NULL;
    SDL_Renderer    *renderer = NULL;
    SDL_Surface     *image = NULL;
    SDL_Texture     *texture = NULL;
    char            *path_image = "test.jpg";

    // init SLD
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Zeltat", 0,0, 700, 400, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    image = IMG_Load(path_image);
    texture = SDL_CreateTextureFromSurface(renderer, image);

    while (1)
    {
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }
 
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
 
    SDL_Quit();

    return (0);
}
