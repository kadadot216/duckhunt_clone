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

//#define	DUCK_HEIGHT (95)
//#define	DUCK_WIDTH (60)
//#define	DUCK_FRAMES (12)
#define	DUCK_HEIGHT (100)
#define	DUCK_WIDTH (135)
#define	DUCK_FRAMES (10)
#define SPRITE_LENGTH (DUCK_WIDTH * DUCK_FRAMES)
//#define	FRAME_DURATION (0.05)
#define	FRAME_DURATION (0.005)

#define PICPATH "assets/rareparrot.png"

struct s_duck {
	sfSprite	*sprite;
	sfTexture	*texture;	
	sfIntRect	hitbox;
	sfVector2f	position;
	sfVector2f	speed;
	t_timer		*timer;
};

typedef struct s_duck	t_duck;

void	kill_duck(t_duck *duck);
void	move_rect(sfIntRect *rect, int offset, int max_value);
void	anim_duck(t_duck *duck, sfRenderWindow *window);
t_duck	*new_duck(void);
sfVector2f	get_sp_position(sfSprite *sprite);

#endif
