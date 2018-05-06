/*
** EPITECH PROJECT, 2018
** spot.c
** File description:
** Functions between duck and player scope
*/

#include "player.h"
#include "duck.h"

int	is_within(int x, int after, int before)
{
	if (x >= after && x <= after + before)
		return (1);
	else
		return (0);
}

int	is_within_duck(mousescope_t *scope, sfVector2f *duckpos)
{
	if (is_within(scope->x, duckpos->x, DUCK_WIDTH) &&
		(is_within(scope->y, duckpos->y, DUCK_HEIGHT)))
		return (1);
	else
		return (0);
}
