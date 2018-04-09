/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main file
*/

#include "window.h"
#include "duck.h"
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

void	close_window(sfRenderWindow *window)
{
	sfRenderWindow_close(window);
}

void	analyse_events(sfRenderWindow *window, sfEvent event)
{
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			close_window(window);
		else if (event.type == sfEvtMouseButtonPressed)
			manage_mouse_click(event.mouseButton);
	}
}


int	main(void)
{
	t_window	*window;
	t_duck		*duck;

	window = create_window(800, 600, 32, "My window");
	sfRenderWindow_setFramerateLimit(window->renderwindow, 60);
	if (!window)
		return (84);
	duck = new_duck();
	while (sfRenderWindow_isOpen(window->renderwindow)) {
		sfRenderWindow_clear(window->renderwindow, sfBlack);
		analyse_events(window->renderwindow, window->event);
		render_the_duck(duck, window->renderwindow);
		sfRenderWindow_display(window->renderwindow);
	}
	kill_duck(duck);
	if (!destroy_window(window))
		return (84);
	return (0);
}

