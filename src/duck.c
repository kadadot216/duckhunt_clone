/*
** EPITECH PROJECT, 2018
** duck.c
** File description:
** Quacks
*/

#include "duck.h"

t_duck	*new_duck(void)
{
	t_duck	*duck;

	duck = malloc(sizeof(t_duck));
	duck->hitbox.top = 0;
	duck->hitbox.left = 0;
	duck->hitbox.width = DUCK_WIDTH;
	duck->hitbox.height = DUCK_HEIGHT;
	duck->texture = sfTexture_createFromFile(PICPATH, NULL);
	duck->sprite = sfSprite_create();
	sfSprite_setTexture(duck->sprite, duck->texture, sfFalse);
	return (duck);
}

void	kill_duck(t_duck *duck)
{
	free(duck);
}

void	move_rect(sfIntRect *rect, int offset, int max_value)
{
	rect->left += offset;
	if (rect->left > max_value)
		rect->left = 0;
}

void	render_the_duck(t_duck *duck, sfRenderWindow *window)
{
	move_rect(&duck->hitbox, DUCK_WIDTH, (DUCK_WIDTH * DUCK_FRAMES));
	sfSprite_setTextureRect(duck->sprite, duck->hitbox);
	sfRenderWindow_drawSprite(window, duck->sprite, NULL);
}
