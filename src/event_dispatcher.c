/*
** EPITECH PROJECT, 2018
** event_dispatcher.c
** File description:
** Dispatch events from player input
*/

#include "my.h"
#include "player.h"
#include "duck.h"
#include "window.h"
#include "term.h"

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

void	display_score(player_t *player, sfText *score, sfRenderWindow *window)
{
	char	*text = my_getbase_nbr(player->score, "0123456789");
	sfText_setString(score, text);
	sfRenderWindow_drawText(window, score, NULL);
}

void	display_lives(int lives, sfSprite *life_sprite, sfRenderWindow *window)
{
	int	i = 0;
	sfVector2f	pos = {760, 560};

	while (i < lives) {
		sfSprite_setPosition(life_sprite, pos);
		pos.x -= 36;
		sfRenderWindow_drawSprite(window, life_sprite, NULL);
		i++;
	}
}

void	dispatch_events(window_t *window, duck_t *duck, player_t *player,
sfText *score)
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
	display_score(player, score, window->render);
	display_lives(player->lives, player->life_sprite, window->render);
	sfRenderWindow_display(window->render);
}
