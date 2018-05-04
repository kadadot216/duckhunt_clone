/*
** EPITECH PROJECT, 2018
** player.h
** File description:
** Header file for player.c
*/

#ifndef __PLAYER_H__
#define __PLAYER_H__

#define LIVES (3)
#define OOR (-1)

#include "duck.h"
#include <SFML/Graphics.h>

typedef struct mousescope_s {
	int	x;
	int	y;
} mousescope_t;

typedef struct player_s {
	int		lives;
	int		score;
	mousescope_t	scope;
} player_t;

mousescope_t	player_shoot(int x, int y);

#endif
