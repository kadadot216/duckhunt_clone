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

typedef struct s_bg t_bg;

struct s_bg {
	sfTexture	*texture;
	sfSprite	*sprite;
};

t_bg	*set_bg(void);
void	unset_bg(t_bg *bg);
void	move_duck(t_duck *duck, t_window *window);
void	run_game(t_window *window, t_timer *gametimer, t_duck *duck);

#endif
