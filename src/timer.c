#include "timer.h"

t_timer		*init_timer(void)
{
	t_timer		*timer;

	timer = malloc(sizeof(t_timer));
	timer->clock = sfClock_create();
	return (timer);
}

void		unset_timer(t_timer *timer)
{
	free(timer);
}

void		get_elapsed_time(t_timer *timer)
{
	timer->time = sfClock_getElapsedTime(timer->clock);
	timer->seconds = (timer->time.microseconds / 1000000.0);
}
