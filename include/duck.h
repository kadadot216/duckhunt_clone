/*
** EPITECH PROJECT, 2018
** duck.h
** File description:
** Header file that helps to quack
*/

#ifndef __DUCK_H__
#define __DUCK_H__

#include <SFML/Graphics.h>
#include "my.h"

#define	DUCK_HEIGHT (95)
#define	DUCK_WIDTH (60)
#define	DUCK_FRAMES (12)

#define PICPATH "assets/ducke.png"

typedef struct	s_duck {
	sfSprite	*sprite;
	sfTexture	*texture;	
	sfIntRect	hitbox;

}		t_duck;

t_duck	*new_duck(void);
void	kill_duck(t_duck *duck);
void	move_rect(sfIntRect *rect, int offset, int max_value);
void	render_the_duck(t_duck *duck, sfRenderWindow *window);

#endif
