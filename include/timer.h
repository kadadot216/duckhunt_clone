#ifndef __TIMER_H__
#define __TIMER_H__

#include "my.h"
#include "SFML/Graphics.h"

typedef	struct timer_s {
	sfClock		*clock;
	sfTime		time;
	float		seconds;
} gametimer_t;

void		get_elapsed_time(gametimer_t *timer);
gametimer_t	init_timer(void);

#endif
