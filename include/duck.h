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

#define	DUCK_SIZE (110)
#define PICPATH "assets/spritesheet.png"

typedef struct	s_duck {
	sfSprite	*sprite;
	sfTexture	*texture;	
	sfIntRect	hitbox;

}		t_duck;

t_duck	*new_duck(void);
void	kill_duck(t_duck *duck);

#endif
