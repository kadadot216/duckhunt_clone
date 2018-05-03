#include "window.h"
#include "duck.h"
#include "game.h"
#include "gamewindow.h"
#include <SFML/Graphics.h>

int	main(void)
{
	t_window	*window;
	t_duck		*duck;
	t_bg		*bg;

	window = create_window(800, 600, 32, "My window");
	bg = set_bg();
	duck = new_duck();
	while (sfRenderWindow_isOpen(window->renderwindow)) {
		sfRenderWindow_clear(window->renderwindow, sfBlack);
		analyse_events(window->renderwindow, window->event);
		sfRenderWindow_drawSprite(window->renderwindow, bg->sprite, NULL);
		anim_duck(duck, window->renderwindow);
		move_duck(duck, window);
		sfRenderWindow_display(window->renderwindow);
	}
	kill_duck(duck);
	unset_bg(bg);
	if (!destroy_window(window))
		return (84);
	return (0);
}

