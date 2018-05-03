/*
** EPITECH PROJECT, 2018
** window.c
** File description:
** File for window
*/

#include "window.h"

window_t	*create_window(unsigned int width, unsigned int height,
			unsigned int depth, char *title)
{
	window_t	*new;
	new = malloc(sizeof(window_t));

	new->title = my_strdup(title);
	new->mode.width = width;
	new->mode.height = height;
	new->mode.bitsPerPixel = depth;
	new->renderwindow = sfRenderWindow_create(new->mode, new->title,
			sfResize | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(new->renderwindow, 60);
	return (new);
}

int		destroy_window(window_t *win)
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
