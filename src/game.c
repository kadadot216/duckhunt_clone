/*
** EPITECH PROJECT, 2018
** game.c
** File description:
** Game management
*/

#include "game.h"

t_bg	*set_bg(void)
{
	t_bg	*bg;

	bg = malloc(sizeof(t_bg));
	bg->texture = sfTexture_createFromFile(BG_PATH, NULL);
	bg->sprite = sfSprite_create();
	sfSprite_setTexture(bg->sprite, bg->texture, sfFalse);
	return (bg);
}

void	unset_bg(t_bg *bg)
{
	sfTexture_destroy(bg->texture);
	sfSprite_destroy(bg->sprite);
	free(bg);
}
