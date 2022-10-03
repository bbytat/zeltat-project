#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2/SDL_image.h> 
#include <stdlib.h> 

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

  
    if (window == NULL)
        printf("error creation window\n");

// loading main img
/*SDL_Texture *image = NULL;

image = IMG_LoadTexture(SDL_Renderer *renderer, const char *test.jpg );
if (!image)
    printf("error loading image\n");

if(window)
{
    SDL_Delay(120000);
    SDL_DestroyWindow(window);
}*/

SDL_Surface *SDL_LoadBMP(const char* (file), "test.bmp"); 
SDL_Surface * tmp = NULL;
SDL_Texture *texture = NULL;

tmp = SDL_LoadBMP("test.bmp");
if(NULL == tmp)
{
    fprintf(stderr, "erreur SDL_LoadBMP : %s", SDL_GetError());
    return(0);
}
texture = SDL_CreateTextureFromSurface(renderer,tmp);
SDL_FreeSurface(tmp);
if(NULL == texture)
{
    fprintf(stderr, "erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
    return(0);
}
}