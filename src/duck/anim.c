/*
** EPITECH PROJECT, 2018
** anim.c
** File description:
** Animation functions for duck
*/

#include "duck.h"

sfVector2f	get_sp_position(sfSprite *sprite)
{
	sfVector2f	position;

	position = sfSprite_getPosition(sprite);
	return (position);
}

void	move_rect(sfIntRect *rect, int offset, int max_value)
{
	rect->left += offset;
	if (rect->left >= max_value)
		rect->left = 0;

}

void	anim_duck(duck_t *duck, sfRenderWindow *window)
{
	get_elapsed_time(&duck->timer);
	if (duck->timer.seconds > FRAME_DURATION) {
		move_rect(&duck->hitbox, DUCK_WIDTH, SPRITE_LENGTH);
		sfClock_restart(duck->timer.clock);
	}
	sfSprite_setTextureRect(duck->sprite, duck->hitbox);
	sfRenderWindow_drawSprite(window, duck->sprite, NULL);
}

