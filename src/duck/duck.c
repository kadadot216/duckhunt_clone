/*
** EPITECH PROJECT, 2018
** duck.c
** File description:
** Quacks
*/

#include "duck.h"
#include "timer.h"
#include "my.h"

duck_t	*new_duck(void)
{
	duck_t	*duck;

	duck = malloc(sizeof(duck_t));
	duck->hitbox.top = 0;
	duck->hitbox.left = 0;
	duck->hitbox.width = DUCK_WIDTH;
	duck->hitbox.height = DUCK_HEIGHT;
	duck->texture = sfTexture_createFromFile(PICPATH, NULL);
	duck->sprite = sfSprite_create();
	duck->timer = inigametimer_t();
	duck->speed.x = 5.0;
	duck->speed.y = 0.0;
	sfSprite_setTexture(duck->sprite, duck->texture, sfFalse);
	return (duck);
}

sfVector2f	get_sp_position(sfSprite *sprite)
{
	sfVector2f	position;

	position = sfSprite_getPosition(sprite);

	return (position);
}

void	remove_duck(duck_t *duck)
{
	sfTexture_destroy(duck->texture);
	sfSprite_destroy(duck->sprite);
	unsegametimer_t(duck->timer);
	free(duck);
}

void	move_rect(sfIntRect *rect, int offset, int max_value)
{
	rect->left += offset;
	if (rect->left >= max_value)
		rect->left = 0;

}

void	anim_duck(duck_t *duck, sfRenderWindow *window)
{
	get_elapsed_time(duck->timer);
	if (duck->timer->seconds > FRAME_DURATION) {
			move_rect(&duck->hitbox, DUCK_WIDTH, SPRITE_LENGTH);
			sfClock_restart(duck->timer->clock);
	}
	sfSprite_setTextureRect(duck->sprite, duck->hitbox);
	sfRenderWindow_drawSprite(window, duck->sprite, NULL);
}

