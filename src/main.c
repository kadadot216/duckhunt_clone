/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main file
*/

#include "game.h"
#include "my.h"
#include "game_events.h"
#include "gamewindow.h"
#include <SFML/Graphics.h>

void	close_window(sfRenderWindow *window)
{
	sfRenderWindow_close(window);
}

int	main(void)
{
	window_t	window = create_window(800, 600, 32, "H U C K D U N T");
	duck_t		duck = setup_duck();
	player_t	player = {3, 0, {OOR, OOR}};

	duck.status = VISIBLE;
	while (sfRenderWindow_isOpen(window.render) && player.lives) {
		my_put_nbr(player.lives);
		my_putchar('\n');
		poll_events(&window, &player, &duck);
		sfRenderWindow_clear(window.render, sfBlack);
		sfRenderWindow_drawSprite(window.render, window.bg.sprite,
			NULL);
		dispatch_events(&window, &duck, &player);
		sfRenderWindow_display(window.render);
	}
	remove_duck(&duck);
	unset_bg(&window.bg);
	return (0);
}

