/*
** EPITECH PROJECT, 2018
** game.c
** File description:
** Game management
*/

#include "game.h"
#include "duck.h"

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

void	go_back(sfVector2f *speed)
{
	speed->x = (- speed->x);
}

void	move_duck(t_duck *duck, t_window *window)
{
	float		maxwidth = window->mode.width - DUCK_WIDTH;
	float		maxheight = window->mode.height - DUCK_HEIGHT;

	duck->position = get_sp_position(duck->sprite);
	if (duck->position.x < 0)
		go_back(&duck->speed);
	if (duck->position.x > maxwidth) {
		go_back(&duck->speed);
		my_put_nbr(duck->speed.x);
		my_putstr("\n");
	}
	if  (duck->position.y == maxheight)
		duck->speed.y = (- duck->speed.y);
	sfSprite_move(duck->sprite, duck->speed);
}
