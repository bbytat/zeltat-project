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
# define PATH_MENU_PLAY "./img/play_menu.png"
# define PATH_MENU_QUIT "./img/quit_menu.png"
# define PATH_MENU "./img/menu.png"

/********************* STRUCTURES *********************/

typedef struct	s_init
{
	SDL_Window		*win;
	SDL_Renderer    *renderer;
    SDL_Surface     *image;
    SDL_Texture     *texture_menu_play;
    SDL_Texture     *texture_menu_quit;
    SDL_Texture     *texture_menu;

} t_init;

/********************* PROTOTYPES *********************/

int	init_SDL(t_init *SDL);
void play(void);
void menu(void);


#endif