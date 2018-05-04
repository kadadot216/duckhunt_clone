/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main file
*/

#include "window.h"
#include "game.h"
#include "duck.h"
#include "player.h"
#include "gamewindow.h"
#include <SFML/Graphics.h>

void	dispatch_events(window_t *window, duck_t *duck, player_t *player)
{
	if (duck->status == VISIBLE) {
		anim_duck(duck, window->render);
		move_duck(duck, window);
	}
}

int	main(void)
{
	window_t	window = create_window(800, 600, 32, "My window");
	duck_t		duck = setup_duck();
	bg_t		bg = set_bg();
	player_t	player = {3, 0};

	duck.status = VISIBLE;
	while (sfRenderWindow_isOpen(window.render)) {
		analyse_events(window.render, window.event);
		sfRenderWindow_clear(window.render, sfBlack);
		sfRenderWindow_drawSprite(window.render, bg.sprite,
			NULL);
		dispatch_events(&window, &duck, &player);
		sfRenderWindow_display(window.render);
	}
	remove_duck(&duck);
	unset_bg(&bg);
	return (0);
}

