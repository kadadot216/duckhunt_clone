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

struct	window_s {
	char		*title;
	sfVideoMode	mode;
	sfRenderWindow	*renderwindow;
	sfEvent		event;
};

typedef struct	window_s window_t;

int		destroy_window(window_t *win);
window_t	*create_window(unsigned int height, unsigned int width,
			unsigned int colordepth, char *title);

#endif
