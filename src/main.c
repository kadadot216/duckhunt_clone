/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main file
*/

#include "game.h"
#include "my.h"
#include "gameobjects.h"
#include "event_dispatcher.h"
#include "event_poll.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>


sfText	*setup_score(sfVideoMode *mode)
{
	sfText	*score = sfText_create();
	sfFont	*font = sfFont_createFromFile("./assets/IBM_VGA8.ttf");
	sfVector2f	position = {0, 0};

	sfText_setFont(score, font);
	sfText_setCharacterSize(score, 30);
	sfText_setColor(score, sfWhite);
	position.x = -700;
	position.y = -500;
	sfText_setOrigin(score, position);
	sfText_setString(score, "");
	return (score);
}

sfText	*unset_score(sfText *text)
{
	sfText_destroy(text);
	text = NULL;
	return (text);
}

int	main(void)
{
	window_t	window = create_window(800, 600,
	32, "H U C K D U N T");
	player_t	player = setup_player();
	sfText		*score = setup_score(&window.mode);
	duck_t		duck = setup_duck();

	srand((unsigned)time(NULL));
	enable_duck(&duck, &player);
	while (sfRenderWindow_isOpen(window.render) && player.lives) {
		poll_events(&window, &player, &duck);
		dispatch_events(&window, &duck, &player, score);
	}
	remove_duck(&duck);
	unset_bg(&window.bg);
	return (0);
}

