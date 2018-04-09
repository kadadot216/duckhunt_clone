/*
** EPITECH PROJECT, 2018
** window.c
** File description:
** File for window
*/

#include "window.h"

t_window	*create_window(unsigned int width, unsigned int height,
			unsigned int depth, char *title)
{
	t_window	*new;
	new = malloc(sizeof(t_window));

	new->title = my_strdup(title);
	new->mode.width = width;
	new->mode.height = height;
	new->mode.bitsPerPixel = depth;
	new->renderwindow = sfRenderWindow_create(new->mode, new->title,
			sfResize | sfClose, NULL);
	return (new);
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
