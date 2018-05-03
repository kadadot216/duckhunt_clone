#ifndef __TIMER_H__
#define __TIMER_H__

#include "my.h"
#include "SFML/Graphics.h"

typedef	struct s_timer {
	sfClock		*clock;
	sfTime		time;
	float		seconds;
}	t_timer;

void		unset_timer(t_timer *timer);
void		get_elapsed_time(t_timer *timer);
t_timer		*init_timer(void);



#endif
