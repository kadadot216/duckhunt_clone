/*
** EPITECH PROJECT, 2018
** game.h
** File description:
** Header file for game.c
*/

#ifndef __GAME_H__
#define __GAME_H__

#include "gameobjects.h"
#include <SFML/Graphics.h>


void	move_duck(duck_t *duck, window_t *window);
void	run_game(window_t *window, gametimer_t *timer,
	duck_t *duck);

#endif
