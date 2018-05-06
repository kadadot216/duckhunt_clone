/*
** EPITECH PROJECT, 2018
** duck.c
** File description:
** Quacks
*/

#include "my.h"
#include "gameobjects.h"

duck_t	setup_duck(void)
{
	duck_t	duck;

	duck.hitbox.top = 0;
	duck.hitbox.left = 0;
	duck.hitbox.width = DUCK_WIDTH;
	duck.hitbox.height = DUCK_HEIGHT;
	duck.status = HIDDEN;
	duck.texture = sfTexture_createFromFile(PICPATH, NULL);
	duck.sprite = sfSprite_create();
	duck.timer = init_timer();
	duck.spawntimer = init_timer();
	duck.speed.x = 0.0;
	duck.speed.y = 0.0;
	sfSprite_setTexture(duck.sprite, duck.texture, sfFalse);
	return (duck);
}

sfVector2f	get_sp_position(sfSprite *sprite)
{
	sfVector2f	position;

	position = sfSprite_getPosition(sprite);
	return (position);
}

void	enable_duck(duck_t *duck, player_t *player)
{
	sfVector2f	pos = {0, 0};

	if (duck->status == HIDDEN)
		duck->status = VISIBLE;
	sfSprite_setPosition(duck->sprite, pos);
	duck->status = VISIBLE;
	duck->hitbox.width = DUCK_WIDTH;
	duck->hitbox.height = DUCK_HEIGHT;
	duck->speed.x = 4.8 + ((double) player->score / 100.0);
	duck->speed.y = 0;
}

void	disable_duck(duck_t *duck)
{
	if (duck->status == VISIBLE)
		duck->status = HIDDEN;
	duck->hitbox.width = 0;
	duck->hitbox.height = 0;
	duck->speed.x = 0;
	duck->speed.y = 0;
	sfClock_restart(duck->spawntimer.clock);
}

int	remove_duck(duck_t *duck)
{
	sfTexture_destroy(duck->texture);
	sfSprite_destroy(duck->sprite);
	return (1);
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

