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

t_window	*create_window(unsigned int height, unsigned int width,
			unsigned int colordepth, char *title)
{
	t_window	*new;
	new = malloc(sizeof(t_window));

	new->height = height;
	new->width = width;
	new->colordepth = colordepth;
	new->title = my_strdup(title);
	return (new);
}

void		init_window(t_window *win)
{
	sfVideoMode	mode = {win->width, win->height, win->colordepth};

	win->renderwindow = sfRenderWindow_create(mode, win->title, sfResize | 
			sfClose, NULL);
}

int		destroy_window(t_window *win)
{
	sfRenderWindow_destroy(win->renderwindow);
	if (win->renderwindow)
		return (-1);
	free(win->title);
	if (win->title)
		return (-1);
	free(win);
	if (win)
		return (-1);
	else
		return (0);
}

#endif
