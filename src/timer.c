#include "timer.h"

gametimer_t		init_timer(void)
{
	gametimer_t		timer;

	timer.clock = sfClock_create();
	return (timer);
}

void		get_elapsed_time(gametimer_t *timer)
{
	timer->time = sfClock_getElapsedTime(timer->clock);
	timer->seconds = (timer->time.microseconds / 1000000.0);
}
