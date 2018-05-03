/*
** EPITECH PROJECT, 2018
** moves.c
** File description:
** Moves file for duck class
*/

#include "window.h"
#include "duck.h"

void	go_back(sfVector2f *speed)
{
	speed->x = (- speed->x);
}

void	flip_sprite_h(sfSprite *sprite, int direction)
{
	sfVector2f	mirror_h = {direction, 1};
	sfSprite_setScale(sprite, mirror_h);
}

void	move_duck(duck_t *duck, window_t *window)
{
	float		maxwidth = window->mode.width - DUCK_WIDTH;
	float		maxheight = window->mode.height - DUCK_HEIGHT;

	duck->position = get_sp_position(duck->sprite);
	if (duck->position.x < 0) {
		go_back(&duck->speed);
		duck->hitbox.left -= DUCK_WIDTH;
		flip_sprite_h(duck->sprite, 1);
	}
	if (duck->position.x > maxwidth) {
		go_back(&duck->speed);
		duck->hitbox.left += DUCK_WIDTH;
		flip_sprite_h(duck->sprite, -1);
	}
	if  (duck->position.y == maxheight)
		duck->speed.y = (- duck->speed.y);
	sfSprite_move(duck->sprite, duck->speed);
}
