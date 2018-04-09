/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main file
*/

#include "window.h"
#include <SFML/Graphics.h>

void	manage_mouse_click(sfMouseButtonEvent event)
{
	if (event.button == sfMouseRight)
		my_putstr("XD\n");
	else if (event.button == sfMouseLeft) {
		my_putstr("Mouse x=");
		my_put_nbr(event.x);
		my_putstr(" y=");
		my_put_nbr(event.y);
		my_putstr("\n");
	}
}

void	analyse_events(sfRenderWindow *window, sfEvent event)
{
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		else if (event.type == sfEvtMouseButtonPressed)
			manage_mouse_click(event.mouseButton);
	}
}


int	main(void)
{
	t_window	*window;

	window = create_window(800, 600, 32, "My window");
	sfRenderWindow_setFramerateLimit(window->renderwindow, 60);
	if (!window)
		return (84);
	while (sfRenderWindow_isOpen(window->renderwindow)) {
		analyse_events(window->renderwindow, window->event);
		sfRenderWindow_clear(window->renderwindow, sfBlack);
		sfRenderWindow_display(window->renderwindow);
	}
	if (!destroy_window(window))
		return (84);
	return (0);
}

