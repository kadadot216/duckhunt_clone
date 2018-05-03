/*
** EPITECH PROJECT, 2018
** timer.h
** File description:
** Header file for time.c
*/

#ifndef __TIMER_H__
#define __TIMER_H__

#include "my.h"
#include "SFML/Graphics.h"

typedef	struct timer_s {
	sfClock		*clock;
	sfTime		time;
	float		seconds;
} gametimer_t;

void		unsegametimer_t(gametimer_t *timer);
void		get_elapsed_time(gametimer_t *timer);
gametimer_t		*inigametimer_t(void);

#endif
