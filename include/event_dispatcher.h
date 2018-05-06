/*
** EPITECH PROJECT, 2018
** event_dispatcher.h
** File description:
** Header file for event_dispatcher.c
*/

#ifndef __EVENT_DISPATCHER_H__
#define __EVENT_DISPATCHER_H__

#include "gameobjects.h"

void	manage_mouse_click(sfMouseButtonEvent event, player_t *player);
void	dispatch_events(window_t *window, duck_t *duck, player_t *player,
sfText *score);

#endif
