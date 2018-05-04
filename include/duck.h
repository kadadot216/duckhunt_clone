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
#include "window.h"

#define	DUCK_HEIGHT (110)
#define	DUCK_WIDTH (110)
#define	DUCK_FRAMES (3)
#define SPRITE_LENGTH (DUCK_WIDTH * DUCK_FRAMES)
#define	FRAME_DURATION (0.05)

#define PICPATH "assets/spritesheet.png"


struct duck_s {
	enum status_e {
		VISIBLE,
		HIDDEN
	}		status;
	sfSprite	*sprite;
	sfTexture	*texture;	
	sfIntRect	hitbox;
	sfVector2f	position;
	sfVector2f	speed;
	gametimer_t	timer;
};

typedef struct duck_s	duck_t;

int		remove_duck(duck_t *duck);
void		move_rect(sfIntRect *rect, int offset, int max_value);
void		anim_duck(duck_t *duck, sfRenderWindow *window);
duck_t		setup_duck(void);
sfVector2f	get_sp_position(sfSprite *sprite);
void		move_duck(duck_t *duck, window_t *window);

#endif
