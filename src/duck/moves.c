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

void	flip_sprite_h(duck_t *duck)
{
	duck->hitbox.width = DUCK_WIDTH * duck->direction;
	duck->direction *= -1;
	if (duck->direction == LEFT)
		duck->hitbox.left += DUCK_WIDTH;
	if (duck->direction == RIGHT)
		duck->hitbox.left -= DUCK_WIDTH;
}

void	move_duck(duck_t *duck, window_t *window)
{
	float		maxwidth = window->mode.width - DUCK_WIDTH;
	float		maxheight = window->mode.height - DUCK_HEIGHT;

	duck->position = get_sp_position(duck->sprite);
	if (duck->position.x < 0) {
		go_back(&duck->speed);
		flip_sprite_h(duck);
	}
	if (duck->position.x > maxwidth) {
		go_back(&duck->speed);
		flip_sprite_h(duck);
	}
	if  (duck->position.y > maxheight)
		duck->speed.y = (- duck->speed.y);
	if  (duck->position.y < 0)
		duck->speed.y = (- duck->speed.y);
	sfSprite_move(duck->sprite, duck->speed);
}
