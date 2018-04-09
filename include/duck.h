/*
** EPITECH PROJECT, 2018
** duck.h
** File description:
** Header file that helps to quack
*/

#ifndef __DUCK_H__
#define __DUCK_H__

#include <SFML/Graphics.h>
#include "timer.h"
#include "my.h"

#define	DUCK_HEIGHT (95)
#define	DUCK_WIDTH (60)
#define	DUCK_FRAMES (12)
#define SPRITE_LENGTH (DUCK_WIDTH * DUCK_FRAMES)
#define	FRAME_DURATION (0.05)

#define PICPATH "assets/ducke.png"

struct s_duck {
	sfSprite	*sprite;
	sfTexture	*texture;	
	sfIntRect	hitbox;
	t_timer		*timer;
};

typedef struct s_duck	t_duck;

t_duck	*new_duck(void);
void	kill_duck(t_duck *duck);
void	move_rect(sfIntRect *rect, int offset, int max_value);
void	anim_duck(t_duck *duck, sfRenderWindow *window);

#endif
