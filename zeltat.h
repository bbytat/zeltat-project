#ifndef ZELTAT_H
# define ZELTAT_H

/********************* LIBRAIRIES *********************/

# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h> 
# include <stdio.h>
# include <stdlib.h>

/*********************** DEFINE ***********************/

# define SCREEN_WIDTH 900
# define SCREEN_HEIGHT 550

/********************* STRUCTURES *********************/

typedef struct	s_init
{
	SDL_Window		*win;
	SDL_Renderer    *renderer;
    SDL_Surface     *image;
    SDL_Texture     *texture;
    char            *path_img;

} t_init;

/********************* PROTOTYPES *********************/

int	init_SDL(t_init *SDL);

#endif