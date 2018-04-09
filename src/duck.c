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
	duck->hitbox.width = DUCK_SIZE;
	duck->hitbox.height = DUCK_SIZE;
	duck->texture = sfTexture_createFromFile(PICPATH, NULL);
	duck->sprite = sfSprite_create();
	sfSprite_setTexture(duck->sprite, duck->texture, sfFalse);
	return (duck);
}

void	kill_duck(t_duck *duck)
{
	free(duck);
}
