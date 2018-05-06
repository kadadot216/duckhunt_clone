/*
** EPITECH PROJECT, 2018
** game_events.c
** File description:
** Game events file
*/

#include "my.h"
#include "player.h"
#include "duck.h"
#include "window.h"

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

int	is_within_duck(mousescope_t *scope, sfVector2f *duckpos)
{
	if (is_within(scope->x, duckpos->x, DUCK_WIDTH) && 
	(is_within(scope->y, duckpos->y, DUCK_HEIGHT)))
		return (1);
	else
		return (0);
}

void	score_points(int *score)
{
	*score += 100;
}

void	term_score(int score)
{
	my_putstr("SCORE: ");
	my_put_nbr(score);
	my_putchar('\n');
}

void	term_lives_left(int lives)
{
	if (lives == 0) {
		my_putstr("You died hunted by the duck.");
	} else {
		my_putstr("Oops! ");
		my_put_nbr(lives);
		my_putstr((lives == 1) ? " life" : " lives");
		my_putstr(" left! ");
	}
	my_putchar('\n');
}


void	shoot_duck(player_t *player, duck_t *duck)
{
	if (is_within_duck(&player->scope, &duck->position)) {
		score_points(&player->score);
		term_score(player->score);
		disable_duck(duck);
	}
	else if (player->scope.x != OOR && player->scope.y != OOR) {
		player->lives--;
		term_lives_left(player->lives);
	}
	player->scope.x = OOR;
	player->scope.y = OOR;

}

void	dispatch_player_action(player_t *player, duck_t *duck)
{
	shoot_duck(player, duck);
}

void	display_score(player_t *player, sfText *score)
{
	char	*text = my_getbase_nbr(player->score, "0123456789");
	sfText_setString(score, text);
}

void	dispatch_events(window_t *window, duck_t *duck, player_t *player, sfText *score)
{
	sfRenderWindow_clear(window->render, sfBlack);
	sfRenderWindow_drawSprite(window->render, window->bg.sprite, NULL);
	get_elapsed_time(&duck->spawntimer);
	if (duck->status == HIDDEN && duck->spawntimer.seconds > 3) {
		enable_duck(duck, player);
	}
	if (duck->status == VISIBLE) {
		dispatch_player_action(player, duck);
		anim_duck(duck, window->render);
		move_duck(duck, window);
	}
	display_score(player, score);
	sfRenderWindow_drawText(window->render, score, NULL);
	sfRenderWindow_display(window->render);
}

