/*
** EPITECH PROJECT, 2018
** game.h
** File description:
** Header file for game.c
*/

#ifndef __GAME_H__
#define __GAME_H__

#include "duck.h"
#include "window.h"
#include <SFML/Graphics.h>

#define BG_PATH "assets/background.png"

typedef struct bg_s bg_t;

struct bg_s {
	sfTexture	*texture;
	sfSprite	*sprite;
};

bg_t	*set_bg(void);
void			unset_bg(bg_t *bg);
void			move_duck(duck_t *duck, window_t *window);
void			run_game(window_t *window, gametimer_t *timer,
	duck_t *duck);

#endif
