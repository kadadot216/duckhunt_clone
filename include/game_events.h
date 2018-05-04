/*
** EPITECH PROJECT, 2018
** game_events.h
** File description:
** Header file for game_events.c
*/

#ifndef __GAME_EVENT_H__
#define __GAME_EVENT_H__

#include "player.h"
#include "game.h"
#include "window.h"

void	manage_mouse_click(sfMouseButtonEvent event, player_t *player);
void	poll_events(window_t *window, player_t *player, duck_t *duck);
void	dispatch_events(window_t *window, duck_t *duck, player_t *player);

#endif
