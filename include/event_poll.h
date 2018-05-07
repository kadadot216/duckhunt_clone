#ifndef __EVENT_POLL_H__
#define __EVENT_POLL_H__

#include <SFML/Graphics.h>
#include "duck.h"
#include "player.h"

void	manage_mouse_click(sfMouseButtonEvent event, player_t *player);
void	poll_events(window_t *window, player_t *player);

#endif
