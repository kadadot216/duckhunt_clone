/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main file
*/

#include "window.h"
#include "duck.h"
#include "game.h"
#include "gamewindow.h"
#include <SFML/Graphics.h>

void	dispatch_events(window_t *window)
{
	duck_t	*duck = NULL;

}

int	main(void)
{
	window_t	*window;
	duck_t		*duck;
	bg_t		*bg;

	window = create_window(800, 600, 32, "My window");
	bg = set_bg();
	duck = new_duck();
	while (sfRenderWindow_isOpen(window->renderwindow)) {
		sfRenderWindow_clear(window->renderwindow, sfBlack);
		analyse_events(window->renderwindow, window->event);
		sfRenderWindow_drawSprite(window->renderwindow, bg->sprite,
			NULL);
		anim_duck(duck, window->renderwindow);
		move_duck(duck, window);
		sfRenderWindow_display(window->renderwindow);
	}
	remove_duck(duck);
	unset_bg(bg);
	if (!destroy_window(window))
		return (84);
	return (0);
}

