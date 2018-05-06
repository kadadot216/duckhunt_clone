/*
** EPITECH PROJECT, 2018
** window.h
** File description:
** Header file for window.c
*/

#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <SFML/Graphics.h>
#include "my.h"

#define BG_PATH "assets/background.png"

typedef struct bg_s {
	sfTexture	*texture;
	sfSprite	*sprite;
}	bg_t;

typedef struct	window_s {
	char		*title;
	sfVideoMode	mode;
	sfRenderWindow	*render;
	sfEvent		event;
	bg_t		bg;
} window_t;


int		destroy_window(window_t *win);
window_t	create_window(unsigned int height, unsigned int width,
			unsigned int colordepth, char *title);
bg_t	set_bg(void);
void	unset_bg(bg_t *bg);
void	close_window(sfRenderWindow *window);

#endif
