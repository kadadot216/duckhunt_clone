/*
** EPITECH PROJECT, 2018
** game.c
** File description:
** Game management
*/

#include "game.h"
#include "duck.h"

bg_t	set_bg(void)
{
	bg_t	bg;

	bg.texture = sfTexture_createFromFile(BG_PATH, NULL);
	bg.sprite = sfSprite_create();
	sfSprite_setTexture(bg.sprite, bg.texture, sfFalse);
	return (bg);
}

void	unset_bg(bg_t *bg)
{
	sfTexture_destroy(bg->texture);
	sfSprite_destroy(bg->sprite);
}
