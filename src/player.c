/*
** EPITECH PROJECT, 2018
** player.c
** File description:
** Player interactions function
*/

#include "player.h"
#include "duck.h"
#include "my.h"

int	within_range_of_duck(int x, int y, sfVector2f pos)
{
	if ((x >= pos.x) && (x <= pos.x + DUCK_WIDTH) &&
			(y >= pos.y && y <= pos.y + DUCK_HEIGHT))
		return (1);
	else
		return (0);
}

mousescope_t	player_shoot(int x, int y)
{
	mousescope_t	pos = {x, y};

	return (pos);
}
