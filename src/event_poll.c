#include "my.h"
#include "player.h"
#include "duck.h"
#include "window.h"
#include "term.h"

void	manage_mouse_click(sfMouseButtonEvent event, player_t *player)
{
	if (event.button == sfMouseLeft) {
		player->scope = player_shoot(event.x, event.y);
	}
}

void	poll_events(window_t *window, player_t *player)
{
	while (sfRenderWindow_pollEvent(window->render, &window->event)) {
		if (window->event.type == sfEvtClosed)
			close_window(window->render);
		else if (window->event.type == sfEvtMouseButtonPressed)
			manage_mouse_click(window->event.mouseButton, player);
	}
}

