/*
** EPITECH PROJECT, 2018
** gamewindow.c
** File description:
** C File for managing interactions between window and the game
*/

#include "gamewindow.h"

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
