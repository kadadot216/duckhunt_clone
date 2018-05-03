/*
** EPITECH PROJECT, 2018
** timer.c
** File description:
** Set Timer structure
*/

#include "timer.h"

gametimer_t		*inigametimer_t(void)
{
	gametimer_t		*timer;

	timer = malloc(sizeof(gametimer_t));
	timer->clock = sfClock_create();
	return (timer);
}

void		unsegametimer_t(gametimer_t *timer)
{
	free(timer);
}

void		get_elapsed_time(gametimer_t *timer)
{
	timer->time = sfClock_getElapsedTime(timer->clock);
	timer->seconds = (timer->time.microseconds / 1000000.0);
}
