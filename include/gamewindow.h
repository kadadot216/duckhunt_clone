/*
** EPITECH PROJECT, 2018
** gamewindow.h
** File description:
** Header file for gamewindow.c
*/

#ifndef __GAMEWINDOW_H__
#define __GAMEWINDOW_H__

#include <SFML/Graphics.h>
#include "my.h"
#include "player.h"
#include "window.h"
#include "duck.h"

void	manage_mouse_click(sfMouseButtonEvent event, player_t *player);
void	close_window(sfRenderWindow *window);
void	poll_events(window_t *window, player_t *player, duck_t *duck);

#endif
