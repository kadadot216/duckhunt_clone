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

typedef struct	s_window {
	unsigned int	height;
	unsigned int	width;
	unsigned int	colordepth;
	char		*title;
	sfRenderWindow	*renderwindow;
	sfEvent		event;
}		t_window;

void		init_window(t_window *win);
int		destroy_window(t_window *win);
t_window	*create_window(unsigned int height, unsigned int width,
			unsigned int colordepth, char *title);


#endif