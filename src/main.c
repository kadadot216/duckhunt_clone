/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main file
*/

#include "window.h"
#include <SFML/Graphics.h>

void	check_winevents(t_window *window)
{
	while (sfRenderWindow_pollEvent(window->renderwindow, &window->event)) {
		if (window->event.type == sfEvtClosed)
			sfRenderWindow_close(window->renderwindow);
	}
}

int	main(void)
{
	t_window	*window;

	window = create_window(800, 600, 32, "My window");
	init_window(window);
	sfRenderWindow_setFramerateLimit(window->renderwindow, 60);
	if (!window)
		return (84);
	while (sfRenderWindow_isOpen(window->renderwindow)) {
		check_winevents(window);
		sfRenderWindow_clear(window->renderwindow, sfBlack);
		sfRenderWindow_display(window->renderwindow);
	}
	destroy_window(window);
	return (0);
}

