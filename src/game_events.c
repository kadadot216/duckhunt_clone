/*
** EPITECH PROJECT, 2018
** game_events.c
** File description:
** Game events file
*/

#include "player.h"
#include "duck.h"
#include "window.h"
#include "gamewindow.h"

void	manage_mouse_click(sfMouseButtonEvent event, player_t *player)
{
	if (event.button == sfMouseLeft) {
		player->scope = player_shoot(event.x, event.y);
	}
}

void	poll_events(window_t *window, player_t *player, duck_t *duck)
{
	while (sfRenderWindow_pollEvent(window->render, &window->event)) {
		if (window->event.type == sfEvtClosed)
			close_window(window->render);
		else if (window->event.type == sfEvtMouseButtonPressed)
			manage_mouse_click(window->event.mouseButton, player);
	}
}

int	is_within(int x, int after, int before)
{
	if (x >= after && x <= after + before)
		return (1);
	else
		return (0);
}

void	shoot_duck(player_t *player, sfVector2f *duck)
{
	if (is_within(player->scope.x, duck->x, DUCK_WIDTH) &&
		is_within(player->scope.y, duck->y, DUCK_HEIGHT)) {
			my_putstr("PAN\n");
	}
	else if (player->scope.x != OOR && player->scope.y != OOR)
		player->lives--;
	player->scope.x = OOR;
	player->scope.y = OOR;

}

void	dispatch_player_action(player_t *player, duck_t *duck)
{
	shoot_duck(player, &duck->position);
}

void	dispatch_events(window_t *window, duck_t *duck, player_t *player)
{
	if (duck->status == VISIBLE) {
		dispatch_player_action(player, duck);
		anim_duck(duck, window->render);
		move_duck(duck, window);
	}
}

