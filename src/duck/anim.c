#include "duck.h"

sfVector2f	get_sp_position(sfSprite *sprite)
{
	sfVector2f	position;

	position = sfSprite_getPosition(sprite);
	return (position);
}

void	move_rect(duck_t *duck, int offset, int max_value)
{
	duck->hitbox.left += offset;
	if (duck->hitbox.left >= max_value && duck->direction == RIGHT)
		duck->hitbox.left = 0;
	if (duck->hitbox.left >= max_value && duck->direction == LEFT)
		duck->hitbox.left = DUCK_WIDTH;

}

void	anim_duck(duck_t *duck, sfRenderWindow *window)
{
	get_elapsed_time(&duck->timer);
	if (duck->timer.seconds > duck->anim_speed) {
		if (duck->direction == RIGHT)
			move_rect(duck, DUCK_WIDTH, SPRITE_LENGTH);
		else
			move_rect(duck,
			DUCK_WIDTH, (SPRITE_LENGTH + DUCK_WIDTH));
		sfClock_restart(duck->timer.clock);
	}
	sfSprite_setTextureRect(duck->sprite, duck->hitbox);
	sfRenderWindow_drawSprite(window, duck->sprite, NULL);
}

