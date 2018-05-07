#ifndef __EVENT_DISPATCHER_H__
#define __EVENT_DISPATCHER_H__

#include "gameobjects.h"

void	manage_mouse_click(sfMouseButtonEvent event, player_t *player);
void	dispatch_events(window_t *window, duck_t *duck, player_t *player,
sfText *score);

#endif
