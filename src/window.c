/*
** EPITECH PROJECT, 2018
** window.c
** File description:
** File for window
*/

#include "window.h"

t_window	*create_window(unsigned int width, unsigned int height,
			unsigned int colordepth, char *title)
{
	t_window	*new;
	new = malloc(sizeof(t_window));

	new->width = width;
	new->height = height;
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
